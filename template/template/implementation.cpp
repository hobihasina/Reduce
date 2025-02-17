
#include <Singular/libsingular.h>


#include <interface/template_interface.hpp>
#include <interface/WorkflowResult.hpp>
#include <interface/ValuesOnPorts.hpp>
#include <interface/Workflow.hpp>
#include <iostream>
#include <stdexcept>
#include <unistd.h>

#include "config.hpp"
#include "singular_functions.hpp"
#include <chrono>
#include <tuple>
//#include "Singular/lists.h"
#include <typeinfo>



NO_NAME_MANGLING


std::string singular_template_compute_StdBasis(std::string const& input_filename
  , std::string const& needed_library
)
{
  init_singular(config::singularLibrary().string());
  load_singular_library(needed_library);
  std::pair<int, lists> input;
  std::pair<int, lists> out;
  std::string ids;
  std::string out_filename;
  std::string out_filename1;
  ids = worker();
  //std::cout << ids << " in singular_..._compute" << std::endl;
  input = deserialize(input_filename, ids);

  ScopedLeftv args(input.first, lCopy(input.second));
  //std::string function_name2 = "stdBasis";

  lists Token = (lists)(args.leftV()->data);

  int L_size = lSize(Token) + 1;
  for (int i = 0; i < L_size; i++) {
    sleftv& listElement = Token->m[i];  // Access each element as `leftv`
    if (listElement.data == NULL) {
      std::cout << "Input: NULL" << std::endl;
    }
    else if (i == 3)
      out_filename1 = listElement.String();
  }
  /*  // Example output filename for debug purposes
   std::cout << "Base filename: " << base_filename << std::endl;
   std::cout << "Output filename: " << out_filename1 << std::endl;
   std::cout << "Type of out_filename1: " << typeid(out_filename1).name() << std::endl;
  */
  //out = call_user_proc(function_name2, needed_library, args);
  //std::cout << "myout " << out.second << std::endl;
  //out_filename = serialize(out.second, base_filename);
  //std::cout << base_filename << std::endl;;


  return out_filename1;
}


std::string singular_template_compute_parseInput(const std::string& input) {

  return input;
}


