
#include <string>

namespace translators {

    namespace constants {
        namespace google {

            const std::string URL = "https://translate.google.com/m"; 
            const std::string HTML_PATTERN = "class=\"result-container\">";
            const char END_PATTERN = '<';
        }

        namespace mymemory {

        const std::string URL = "http://api.mymemory.translated.net/get";
        const std::string RESPONSE_KEY = "responseData";
        const std::string TRANSLATION_KEY = "translatedText";
        }
    }
}