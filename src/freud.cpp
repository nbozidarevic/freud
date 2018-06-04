#include <iostream>
#include <fstream>
#include <unordered_map>

#include "BrainfuckFormatter.h"

using namespace std;

void print_header() {
  cout
    << "Freud – A toolset for working with the Brainfuck programming language"
    << endl << endl;
}

void print_unknown_command_error(string& command) {
  cout << "Unknown command \"" << command << "\"." << endl << endl;
}

void print_parametre_error(string& error) {
  cout << error << endl << endl;
}

void print_usage() {
  cout << "Usage:" << endl;
  cout << "\tfreud [command] [parametres]" << endl << endl;

  cout << "Supported commands:" << endl << endl;

  cout << "\tformat [-i input-file] [-o output-file] [-m]" << endl << endl;
  cout
    << "\t\tFormats the received Brainfuck program by removing all" << endl
    << "\t\tinvalid characters and adding indentation." << endl << endl;
  cout
    << "\t\tIf no input or output file is specified, the standard" << endl
    << "\t\tinput or output are used, respectively." << endl << endl;
  cout
    << "\t\tIf the -m flag is specified, all whitespace is removed."
    << endl << endl;
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

    if (param == "-i" || param == "-o") {
      ++i;
      if (i < argc) {
        value = string(argv[i]);
      } else {
        throw "Parameter \"" + param + "\" is missing a value.";
      }
    } else if (command == "format" && param == "-m") {
    } else {
      throw "Unknown parametre \"" + param + "\".";
    }

    params[param] = value;

    ++i;
  }

  return params;
}

int format(unordered_map<string, string>& params) {
  istream *inputStream = &cin;
  unordered_map<string, string>::iterator input = params.find("-i");
  if (input != params.end()) {
    inputStream = new ifstream(input->second, ifstream::in);
  }

  ostream *outputStream = &cout;
  unordered_map<string, string>::iterator output = params.find("-o");
  if (output != params.end()) {
    outputStream = new ofstream(output->second, ifstream::out);
  }

  BrainfuckFormatter bff(
    *inputStream,
    *outputStream,
    params.find("-m") != params.end()
  );
  bff.run();

  if (input != params.end()) {
    delete inputStream;
  }
  if (output != params.end()) {
    delete outputStream;
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
  } catch (string& error) {
    print_parametre_error(error);
    print_usage();
    return 0;
  }

  if (command == "format") {
    return format(params);
  } else {
    print_unknown_command_error(command);
    print_usage();
    return 0;
  }
}
