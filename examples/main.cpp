
#include <iostream>
#include "translators.hpp"


int main(int argc, char const *argv[])
{
    translators::GoogleTranslator g("en", "de");
    translators::MyMemoryTranslator m("en", "de");

    std::string g_translation = g.translate("hi man");
    std::string m_translation = m.translate("hi man");
    
    std::cout << "google translation: " << g_translation << std::endl;
    std::cout << "mymemory translation: " << m_translation << std::endl;
    
    return 0;
}
