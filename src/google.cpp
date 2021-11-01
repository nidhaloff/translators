
#include <iostream>

#include <cpr/cpr.h>

#include "constants.hpp"
#include "google.hpp"

namespace translators {

    GoogleTranslator::GoogleTranslator(const std::string& source, const std::string& target)
    : BaseTranslator(source, target)
    {
    }

    
    std::string GoogleTranslator::translate(const std::string& text) {
        // get a html response
        const cpr::Response r = cpr::Get(
                            cpr::Url{constants::google::URL}, 
                            cpr::Parameters{
                                {"tl", m_target},
                                {"sl", m_source},
                                {"q", text}
                            }
        );

        // scrap and search html
        auto startHtmlIdx = r.text.find(constants::google::HTML_PATTERN);
        if (startHtmlIdx == std::string::npos) {
            throw "No translation found!";
        }

        // Find the translated content using the defined html/css pattern
        startHtmlIdx += constants::google::HTML_PATTERN.length();
        const std::string body = r.text.substr(startHtmlIdx);

        // Find end html index to cut text and get the translation
        auto endHtmlIdx = body.find(constants::google::END_PATTERN);
        const std::string translation = body.substr(0, endHtmlIdx);
        return translation;
    }
}