#include <pnetc/op/singular_template/compute.hpp>
#include <string>
#include <interface/template_interface.hpp>
#include <util-generic/dynamic_linking.hpp>
#include <iostream>

namespace pnetc
{
  namespace op
  {
    namespace singular_template
    {
      void compute
        ( const std::string& input
        , const std::string& library_name
        , std::string& output
        )
      {
#line 24 "/home/atraore/gpi/try_gpi/Reduce/template/workflow/template.xpnet"

    output=  RESOLVE_INTERFACE_FUNCTION( singular_template_compute_StdBasis) (input,library_name);
          std::cout<<"****output1****"<<output<<std::endl;
            		
      }
    }
  }
}