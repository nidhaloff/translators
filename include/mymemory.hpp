#pragma once

#include <string>
#include "base.hpp"


namespace translators {

    class MyMemoryTranslator final: public BaseTranslator {

        public:
        MyMemoryTranslator(const std::string& source, const std::string& target);
        std::string translate(const std::string& text) override;
    };
}