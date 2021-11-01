
#include <iostream>

#include <cpr/cpr.h>
#include "json.hpp"
#include "constants.hpp"
#include "mymemory.hpp"

namespace translators {

    MyMemoryTranslator::MyMemoryTranslator(const std::string& source, const std::string& target)
    : BaseTranslator(source, target)
    {
    }

    
    std::string MyMemoryTranslator::translate(const std::string& text) {
        
        const std::string langpair = m_source + '|' + m_target;
        
        // get a html response
        const cpr::Response r = cpr::Get(
                            cpr::Url{constants::mymemory::URL}, 
                            cpr::Parameters{
                                {"langpair", langpair},
                                {"q", text}
                            }
        );
        const nlohmann::json& body = nlohmann::json::parse(r.text);
        const std::string& translation = body["responseData"]["translatedText"];

        return translation;
    }
}