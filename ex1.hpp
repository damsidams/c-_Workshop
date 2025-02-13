#pragma once
#include <string>
#include <iostream>

class MemeGenerator {
    private:
        std::string topText;
        std::string bottomText;
        std::string topEmoji;
        std::string bottomEmoji;

    public:
        MemeGenerator(std::string topText, std::string bottomText, 
                     std::string topEmoji = "😰", std::string bottomEmoji = "👷") 
            : topText(topText), bottomText(bottomText), 
              topEmoji(topEmoji), bottomEmoji(bottomEmoji) {};

        void generateMeme() {
            std::cout
                << topEmoji << topText << topEmoji << "\n\n"
                << bottomEmoji << bottomText << bottomEmoji << std::endl;
        };
};
