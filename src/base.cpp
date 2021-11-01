
#include <iostream>
#include "base.hpp"

namespace translators {

    BaseTranslator::BaseTranslator(const std::string& source, const std::string& target)
    : m_source{source}, m_target{target}
    {
    }

    const std::string& BaseTranslator::getSourceLanguage() const {
        return m_source;
    }


    const std::string& BaseTranslator::getTargetLanguage() const {
        return m_target;
    }

    void BaseTranslator::setSourceLanguage(const std::string& language) {
        m_source = language;
    }
    
    void BaseTranslator::setTargetLanguage(const std::string& language) {
        m_target = language;
    }
}