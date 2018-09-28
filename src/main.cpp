#include <iostream>
#include <fstream>
#include <unordered_map>

#include "BrainfuckCompiler.h"
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
    << "[parametres]"
    << endl << endl;

  cout << "Supported commands:" << endl << endl;

  cout
    << "\t\033[1mcompile\033[0m "
    << "[-i input-file] "
    << "[-o output-file]"
    << endl << endl;
  cout
    << "\t\tCompiles the specified C program to Brainfuck." << endl << endl;
  cout
    << "\t\tIf no input file is specified, the standard" << endl
    << "\t\tinput is used." << endl << endl;
  cout
    << "\t\tIf no output file is specified, the standard" << endl
    << "\t\toutput is used." << endl << endl;

  cout
    << "\t\033[1mformat\033[0m "
    << "[-i input-file] "
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
    << "\t\tIf no input file is specified, the standard" << endl
    << "\t\tinput is used." << endl << endl;
  cout
    << "\t\tIf the -m flag is specified, all whitespace is removed."
    << endl << endl;

  cout
    << "\t\033[1mrun\033[0m "
    << "[-i input-file]"
    << endl << endl;
  cout
    << "\t\tExecutes the specified Brainfuck program." << endl << endl;
  cout
    << "\t\tIf no input file is specified, the standard" << endl
    << "\t\tinput is used." << endl << endl;
}

unordered_map<string, string> parse_params(
  string& command,
  int argc,
  char **argv
) {
  unordered_map<string, string> params;

  int i = 0;
  while (i < argc) {
    string param = string(argv[i]);
    string value;

    if ((command == "compile" || command == "format") && param == "-o") {
      ++i;
      if (i < argc) {
        params["output"] = string(argv[i]);
      } else {
        throw "Parameter -o is missing a value.";
      }
    } else if (command == "format" && param == "-m") {
      params["minify"] = "minify";
    } else if (param == "-i") {
      ++i;
      if (i < argc) {
        params["input"] = string(argv[i]);
      } else {
        throw "Parameter -i is missing a value.";
      }
    } else {
      throw "Unknown parametre \"" + param + "\".";
    }

    ++i;
  }

  return params;
}

int format(unordered_map<string, string>& params) {
  unordered_map<string, string>::iterator input = params.find("input");
  istream *codeStream =
    input != params.end()
      ? new ifstream(input->second, ifstream::in)
      : &cin;

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

  if (input != params.end()) {
    delete codeStream;
  }
  if (output != params.end()) {
    delete formattedCodeStream;
  }

  return 0;
}

int compile(unordered_map<string, string>& params) {
  unordered_map<string, string>::iterator input = params.find("input");
  istream *codeStream =
    input != params.end()
      ? new ifstream(input->second, ifstream::in)
      : &cin;

  unordered_map<string, string>::iterator output = params.find("output");
  ostream *compiledCodeStream =
    output != params.end()
      ? new ofstream(output->second, ifstream::out)
      : &cout;

  BrainfuckCompiler bfc(
    *codeStream,
    *compiledCodeStream
  );
  bfc.run();

  if (input != params.end()) {
    delete codeStream;
  }
  if (output != params.end()) {
    delete compiledCodeStream;
  }

  return 0;
}

int run(unordered_map<string, string>& params) {
  unordered_map<string, string>::iterator input = params.find("input");
  istream *codeStream =
    input != params.end()
      ? new ifstream(input->second, ifstream::in)
      : &cin;

  BrainfuckRunner bfr(*codeStream, cin, cout);
  bfr.run();

  if (input != params.end()) {
    delete codeStream;
  }

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

    if (command == "compile") {
      return compile(params);
    }
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
