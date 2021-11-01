#pragma once

#include <string>
#include "base.hpp"


namespace translators {

    class GoogleTranslator final: public BaseTranslator {

        public:
        GoogleTranslator(const std::string& source, const std::string& target);
        std::string translate(const std::string& text) override;
    };
}