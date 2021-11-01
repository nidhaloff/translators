#pragma once

#include <string>


namespace translators {

    class BaseTranslator {
        public:
        BaseTranslator(const std::string& source, const std::string& target);

        // getters
        const std::string& getSourceLanguage() const;
        const std::string& getTargetLanguage() const;
        
        // setters
        void setSourceLanguage(const std::string& language);
        void setTargetLanguage(const std::string& language);
        
        // need to be defined for each single translator
        virtual std::string translate(const std::string& text) = 0;
        
        protected:
        std::string m_source;
        std::string m_target;
    };
}