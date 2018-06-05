#include <iostream>
#include <fstream>
#include <unordered_map>

#include "BrainfuckFormatter.h"
#include "BrainfuckRunner.h"

using namespace std;

void print_header() {
  cout
    << "Freud – A toolset for working with the Brainfuck programming language"
    << endl << endl;
}

void print_unknown_command_error(string& command) {
  cout << "Unknown command \"" << command << "\"." << endl << endl;
}

void print_caught_error(char const* error) {
  cout << error << endl << endl;
}

void print_usage() {
  cout << "Usage:" << endl;
  cout
    << "\t\033[1mfreud\033[0m "
    << "\033[4mcommand\033[0m "
    << "\033[4mfile\033[0m "
    << "[parametres]"
    << endl << endl;

  cout << "Supported commands:" << endl << endl;

  cout
    << "\t\033[1mformat\033[0m "
    << "\033[4mfile\033[0m "
    << "[-o output-file] "
    << "[-m]"
    << endl << endl;
  cout
    << "\t\tFormats the specified Brainfuck program by removing all" << endl
    << "\t\tinvalid characters and adding indentation." << endl << endl;
  cout
    << "\t\tIf no output file is specified, the standard" << endl
    << "\t\toutput is used." << endl << endl;
  cout
    << "\t\tIf the -m flag is specified, all whitespace is removed."
    << endl << endl;

  cout
    << "\t\033[1mrun\033[0m "
    << "\033[4mfile\033[0m"
    << endl << endl;
  cout
    << "\t\tExecutes the specified Brainfuck program." << endl << endl;
}

unordered_map<string, string> parse_params(
  string& command,
  int argc,
  char **argv
) {
  if (argc == 0) {
    throw "No file was specified.";
  }

  unordered_map<string, string> params;
  params["code"] = string(argv[0]);

  int i = 1;
  while (i < argc) {
    string param = string(argv[i]);
    string value;

    if (command == "format" && param == "-o") {
      ++i;
      if (i < argc) {
        params["output"] = string(argv[i]);
      } else {
        throw "Parameter -o is missing a value.";
      }
    } else if (command == "format" && param == "-m") {
      params["minify"] = "minify";
    } else {
      throw "Unknown parametre \"" + param + "\".";
    }

    ++i;
  }

  return params;
}

int format(unordered_map<string, string>& params) {
  unordered_map<string, string>::iterator code = params.find("code");
  if (code == params.end()) {
    throw "Missing Brainfuck file to format.";
  }
  istream *codeStream = new ifstream(code->second, ifstream::in);

  unordered_map<string, string>::iterator output = params.find("output");
  ostream *formattedCodeStream =
    output != params.end()
      ? new ofstream(output->second, ifstream::out)
      : &cout;

  BrainfuckFormatter bff(
    *codeStream,
    *formattedCodeStream,
    params.find("minify") != params.end()
  );
  bff.run();

  delete codeStream;
  if (output != params.end()) {
    delete formattedCodeStream;
  }

  return 0;
}

int run(unordered_map<string, string>& params) {
  unordered_map<string, string>::iterator code = params.find("code");
  if (code == params.end()) {
    throw "Missing Brainfuck file to run.";
  }
  istream *codeStream = new ifstream(code->second, ifstream::in);

  BrainfuckRunner bfr(*codeStream, cin, cout);
  bfr.run();

  delete codeStream;

  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    print_header();
    print_usage();
    return 0;
  }

  string command = string(argv[1]);
  unordered_map<string, string> params;
  try {
    params = parse_params(
      command,
      argc - 2,
      argv + 2
    );

    if (command == "format") {
      return format(params);
    }
    if (command == "run") {
      return run(params);
    }
  } catch (char const* error) {
    print_caught_error(error);
    print_usage();
    return 0;
  }

  print_unknown_command_error(command);
  print_usage();
  return 0;
}
