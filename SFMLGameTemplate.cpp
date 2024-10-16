#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <iostream>

using namespace std;
/*
Creation de 4 sorts aleatoires
Cliquer : executer le sort et le supprimer de la barre de sort
Lorsque le joueur passe ou qu'il n'y a plus de sort dans la barre, les sorts restants sont supprimes et 4 nouveaux sorts sont piochés


*/

//the proprieties of all the spells
struct Sort
{
    int dmg;
    int costMana;
    int heal;
    sf::Sprite img;
    string name;
    bool isVisible = true;
};

//the proprieties of all the enemies
struct Enemies
{
    int hp;
    int resistance;
    int dmg;
    

};
//place the spells in your spellbar
void RemplirBarre(const int NB_SORTS_BARRE, int& nb_alea, const int NB_SORTS, Sort  barreDeSorts[4], Sort  listSort[6], sf::RenderWindow& window);
const int DECALAGE_SORT_X = 150;


int main()
{
    int position = 0;
    int currentPlace = 1;
    bool titlepage = true;
    bool game = false;
    int mana = 8;
    int vie = 30;
    int enemyHp = 10;
    int resistance = 0;
    int enemyCount = 0;
    srand(time(NULL));
    int nb_alea = std::rand() % 9;
    int enemyIdentity = nb_alea;
    const int NB_SPELLS_BAR = 4;
    const int NB_SPELLS = 6;
    const int NB_ENEMIES = 11;
    Sort spellBar[NB_SPELLS_BAR];
    bool cliking = true;
    bool endTurn = false;
    int dmg[6];
    dmg[0] = 12;
    dmg[1] = 20;
    dmg[2] = 40;
    dmg[3] = 36;
    dmg[4] = 20;
    dmg[5] = 0;
    char textMana = mana;
    int coins = 0;
    Sort listSpell[NB_SPELLS];
    Enemies currentEnemy[NB_ENEMIES];
    int spellsInBar = 4;
    char manaChar = mana;
    



    // Create the main window
    sf::RenderWindow window(sf::VideoMode(816, 624), "SFML window");

    // Load sprites to display
    sf::Texture titlePage_tex;
    if (!titlePage_tex.loadFromFile("Res/Walvak/100213.png"))
        return EXIT_FAILURE;
    sf::Texture titleOver_tex;
    if (!titleOver_tex.loadFromFile("Res/Walvak/100218.png"))
        return EXIT_FAILURE;
    sf::Texture jouer_tex;
    if (!jouer_tex.loadFromFile("Res/Walvak/'jouer'.png"))
        return EXIT_FAILURE;
    sf::Texture sl1_tex;
    if (!sl1_tex.loadFromFile("Res/Walvak/salle1.png"))
        return EXIT_FAILURE;
    sf::Texture sl2_tex;
    if (!sl1_tex.loadFromFile("Res/Walvak/salle2.png"))
        return EXIT_FAILURE;
    sf::Texture sl3_tex;
    if (!sl1_tex.loadFromFile("Res/Walvak/salle3.png"))
        return EXIT_FAILURE;
    
    sf::Texture passer_tex;
    if (!passer_tex.loadFromFile("Res/Walvak/passer.png"))
        return EXIT_FAILURE;

    sf::Texture enemy_tex;
    if (!sl1_tex.loadFromFile("Res/Walvak/100521.png"))
        return EXIT_FAILURE;
   
    sf::Texture A_tex;
    if (!A_tex.loadFromFile("Res/Walvak/A.png"))
        return EXIT_FAILURE;
    sf::Texture B_tex;
    if (!B_tex.loadFromFile("Res/Walvak/B.png"))
        return EXIT_FAILURE;
    sf::Texture C_tex;
    if (!C_tex.loadFromFile("Res/Walvak/C.png"))
        return EXIT_FAILURE;
    sf::Texture D_tex;
    if (!D_tex.loadFromFile("Res/Walvak/D.png"))
        return EXIT_FAILURE;
    sf::Texture E_tex;
    if (!E_tex.loadFromFile("Res/Walvak/E.png"))
        return EXIT_FAILURE;
    sf::Texture F_tex;
    if (!F_tex.loadFromFile("Res/Walvak/F.png"))
        return EXIT_FAILURE;
    
    
    sf::Sprite titlePage(titlePage_tex);
    titlePage.setPosition(sf::Vector2f(0, 0));
    if (!titlePage_tex.loadFromFile("Res/Walvak/100213.png"))
        return EXIT_FAILURE;
    sf::Sprite jouer(jouer_tex);
    jouer.setOrigin(sf::Vector2f(25, 12.5));
    jouer.setScale(sf::Vector2f(6, 6));
    jouer.setPosition(sf::Vector2f(408, 312));
    if (!jouer_tex.loadFromFile("Res/Walvak/'jouer'.png"))
        return EXIT_FAILURE;
    sf::Sprite sl1(sl1_tex);
    sl1.setScale(sf::Vector2f(0.816, 0.843));
    sl1.setPosition(sf::Vector2f(0, 0));
    if (!sl1_tex.loadFromFile("Res/Walvak/salle1.png"))
        return EXIT_FAILURE;
    
    sf::Sprite enemy(enemy_tex);
    enemy.setScale(sf::Vector2f(1, 1));
    enemy.setPosition(sf::Vector2f(300, 200));
    if (!enemy_tex.loadFromFile("Res/Walvak/100521.png"))
        return EXIT_FAILURE;

    sf::Sprite passer(passer_tex);
    passer.setScale(sf::Vector2f(2, 2));
    passer.setPosition(sf::Vector2f(650, 500));
    if (!passer_tex.loadFromFile("Res/Walvak/passer.png"))
        return EXIT_FAILURE;
    
    sf::Sprite gameOver(titleOver_tex);
    gameOver.setPosition(sf::Vector2f(0, 0));
    if (!titleOver_tex.loadFromFile("Res/Walvak/100218.png"))
        return EXIT_FAILURE;

    sf::IntRect frameSprite;
    
    sf::Text manaText;
    manaText.setString(to_string(mana));
    manaText.setCharacterSize(30);
    manaText.setPosition(100, 100);
    
    

    titlePage.setTexture(titlePage_tex);
    sl1.setTexture(sl1_tex);
    enemy.setTexture(enemy_tex);
    enemy.setTextureRect(frameSprite);
    
    // insert the content in all the proprieties of the spells
    listSpell[0].costMana = 4;
    listSpell[0].dmg = 0;
    listSpell[0].heal = 5;
    listSpell[0].img = sf::Sprite(A_tex);
    listSpell[0].name = "A";
    
    listSpell[1].costMana = 2;
    listSpell[1].dmg = 2;
    listSpell[1].heal = 0;
    listSpell[1].img = sf::Sprite(B_tex);
    listSpell[1].name = "B";

    listSpell[2].costMana = 3;
    listSpell[2].dmg = 4;
    listSpell[2].heal = 0;
    listSpell[2].img = sf::Sprite(C_tex);
    listSpell[2].name = "C";

    listSpell[3].costMana = 3;
    listSpell[3].dmg = 1;
    listSpell[3].heal = 0;
    listSpell[3].img = sf::Sprite(D_tex);
    listSpell[3].name = "D";

    listSpell[4].costMana = 5;
    listSpell[4].dmg = 5;
    listSpell[4].heal = 1;
    listSpell[4].img = sf::Sprite(E_tex);
    listSpell[4].name = "E";

    listSpell[5].costMana = 6;
    listSpell[5].dmg = 3;
    listSpell[5].heal = 2;
    listSpell[5].img = sf::Sprite(F_tex);
    listSpell[5].name = "F";

    // insert the content in all the proprieties of the foes
    currentEnemy[0].hp = 10;
    currentEnemy[0].resistance = 0;
    currentEnemy[0].dmg = 4;
    
    currentEnemy[1].hp = 7;
    currentEnemy[1].resistance = 0;
    currentEnemy[1].dmg = 3;
    
    currentEnemy[2].hp = 15;
    currentEnemy[2].resistance = 0;
    currentEnemy[2].dmg = 2;

    currentEnemy[3].hp = 3;
    currentEnemy[3].resistance = 0;
    currentEnemy[3].dmg = 6;

    currentEnemy[4].hp = 9;
    currentEnemy[4].resistance = 0;
    currentEnemy[4].dmg = 3;

    currentEnemy[5].hp = 22;
    currentEnemy[5].resistance = 0;
    currentEnemy[5].dmg = 1;
    
    currentEnemy[6].hp = 16;
    currentEnemy[6].resistance = 0;
    currentEnemy[6].dmg = 5;

    currentEnemy[7].hp = 1;
    currentEnemy[7].resistance = 0;
    currentEnemy[7].dmg = 25;

    currentEnemy[8].hp = 5;
    currentEnemy[8].resistance = 0;
    currentEnemy[8].dmg = 2;

    currentEnemy[9].hp = 6;
    currentEnemy[9].resistance = 0;
    currentEnemy[9].dmg = 5;
    
    //don't work yet, for a future improvement
    currentEnemy[10].hp = 120;
    currentEnemy[10].resistance = 1;
    currentEnemy[10].dmg = 6;

    sf::Clock clock;

    // Start the game loop
    RemplirBarre(NB_SPELLS_BAR, nb_alea, NB_SPELLS, spellBar, listSpell, window);
    while (window.isOpen())
    {
        
        
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            // Process events
            sf::Event userevent;
            window.clear();
            while (window.pollEvent(userevent))
            {
                if (mousePosition.x > 333 && mousePosition.x < 666 && mousePosition.y > 274 && mousePosition.y < 549)
                {
                    if (userevent.type == sf::Event::MouseButtonPressed)
                    {
                        titlepage = false;
                        game = true;
                    }
                }
                if (userevent.type == sf::Event::MouseButtonPressed && game == true)
                {
                    cliking = true;
                }
                //to pass the turn
                if (userevent.type == sf::Event::KeyPressed  && game == true)
                {
                    endTurn = true;
                }
                
                // Close window: exit
                if (userevent.type == sf::Event::Closed)
                    window.close();



            }
                
                if (clock.getElapsedTime().asSeconds() > 3)
                {
                    
                    clock.restart();
                }


                // Draw the sprite
                if (titlepage)
                {
                    window.draw(titlePage);
                    window.draw(jouer);
                }
                if (game)
                {
                    
                    if (mana > 0)
                    {
                        //set the proprieties and show the current enemy
                        if (enemyIdentity == 0)
                        {
                            frameSprite.left = 511.f;
                            frameSprite.top = 1929.f;
                            frameSprite.width = 227.f;
                            frameSprite.height = 253.f;
                            enemy.setTextureRect(frameSprite);
                            
                        }
                        if (enemyIdentity == 1)
                        {
                            frameSprite.left = 1679.f;
                            frameSprite.top = 2214.f;
                            frameSprite.width = 201.f;
                            frameSprite.height = 197.f;
                            enemy.setTextureRect(frameSprite);
                        }
                        if (enemyIdentity == 2)
                        {
                            frameSprite.left = 1637.f;
                            frameSprite.top = 1947.f;
                            frameSprite.width = 211.f;
                            frameSprite.height = 235.f;
                            enemy.setTextureRect(frameSprite);                                     
                        }
                        if (enemyIdentity == 3)
                        {
                            frameSprite.left = 1008.f;
                            frameSprite.top = 2194.f;
                            frameSprite.width = 183.f;
                            frameSprite.height = 218.f;
                            enemy.setTextureRect(frameSprite);
                        }
                        if (enemyIdentity == 4)
                        {
                            frameSprite.left = 548.f;
                            frameSprite.top = 2194.f;
                            frameSprite.width = 311.f;
                            frameSprite.height = 218.f;
                            enemy.setTextureRect(frameSprite);
                        }
                        if (enemyIdentity == 5)
                        {
                            frameSprite.left = 557.f;
                            frameSprite.top = 1651.f;
                            frameSprite.width = 222.f;
                            frameSprite.height = 270.f;
                            enemy.setTextureRect(frameSprite);
                        }
                        if (enemyIdentity == 6)
                        {
                            frameSprite.left = 615.f;
                            frameSprite.top = 1354.f;
                            frameSprite.width = 301.f;
                            frameSprite.height = 289.f;
                            enemy.setTextureRect(frameSprite);
                        }
                        if (enemyIdentity == 7)
                        {
                            frameSprite.left = 185.f;
                            frameSprite.top = 2426.f;
                            frameSprite.width = 161.f;
                            frameSprite.height = 176.f;
                            enemy.setTextureRect(frameSprite);
                        }
                        if (enemyIdentity == 8)
                        {
                            frameSprite.left = 1519.f;
                            frameSprite.top = 2476.f;
                            frameSprite.width = 121.f;
                            frameSprite.height = 126.f;
                            enemy.setTextureRect(frameSprite);
                        }
                        if (enemyIdentity == 9)
                        {
                            frameSprite.left = 1142.f;
                            frameSprite.top = 2467.f;
                            frameSprite.width = 137.f;
                            frameSprite.height = 135.f;
                            enemy.setTextureRect(frameSprite);
                        }
                        if (enemyIdentity == 10)
                        {
                            frameSprite.left = 1323.f;
                            frameSprite.top = 889.f;
                            frameSprite.width = 465.f;
                            frameSprite.height = 415.f;
                            enemy.setPosition(sf::Vector2f(140, 70));
                            enemy.setTextureRect(frameSprite);
                        }
                        //when using a spell
                        if (cliking)
                        {
                            if (mousePosition.y < window.getSize().y - (150 - 128) && mousePosition.y > window.getSize().y - 150)
                            {
                               
                                for (int sortIndex = 0; sortIndex < NB_SPELLS_BAR; ++sortIndex)
                                {                                
                                    if (mousePosition.x > spellBar[sortIndex].img.getPosition().x && mousePosition.x < spellBar[sortIndex].img.getPosition().x + 128)
                                    {
                                        if (spellBar[sortIndex].costMana <= mana)
                                        {
                                            if (!spellBar[sortIndex].isVisible) continue;
                                            enemyHp = enemyHp - (spellBar[sortIndex].dmg - currentEnemy[enemyIdentity].resistance);
                                            vie = vie + spellBar[sortIndex].heal;
                                            std::cout << vie << "vie" << std::endl;
                                            mana = mana - spellBar[sortIndex].costMana;
                                            std::cout << mana << std::endl;
                                            std::cout << enemyHp << "hp" << std::endl;
                                            spellBar[sortIndex].isVisible = false;
                                            spellsInBar -= 1;
                                        }
                                        
                                    }

                                }
                            }
                            else if (mousePosition.y < 500 + (37*2) && mousePosition.y > 499 && mousePosition.x < 650 + (37*2) && mousePosition.y > 649)
                            {
                                vie = vie - currentEnemy[enemyIdentity].dmg;
                                srand(time(NULL));
                                mana = std::rand() % 15;
                                RemplirBarre(NB_SPELLS_BAR, nb_alea, NB_SPELLS, spellBar, listSpell, window);
                                spellsInBar = 4;
                            }
                        }
                        //set the next turn
                        if (endTurn)
                        {
                            vie = vie - currentEnemy[enemyIdentity].dmg;
                            srand(time(NULL));
                            mana = std::rand() % 15;
                            RemplirBarre(NB_SPELLS_BAR, nb_alea, NB_SPELLS, spellBar, listSpell, window);
                            spellsInBar = 4;
                            endTurn = false;
                        }
                        if (enemyHp < 1)
                        {
                            currentPlace = currentPlace + 1;
                            
                            if (enemyCount < 19)
                            {
                                srand(time(NULL));
                                nb_alea = std::rand() % 9;
                                enemyIdentity = nb_alea;
                                enemyHp = currentEnemy[enemyIdentity].hp;
                                enemyCount = enemyCount + 1;
                                std::cout << enemyCount << "oi" << std::endl;
                                srand(time(NULL));
                                mana = mana + std::rand() % 5;
                            }
                            else
                            {
                                enemyIdentity = 10;
                                enemyHp = currentEnemy[enemyIdentity].hp;
                            }

                        }
                        window.draw(sl1);
                        window.draw(enemy);                     
                        window.draw(passer);
                        window.draw(manaText);
                        for (int sortIndex = 0; sortIndex < NB_SPELLS_BAR; ++sortIndex)
                        {
                            if (!spellBar[sortIndex].isVisible) continue;
                            window.draw(spellBar[sortIndex].img);

                        }
                        cliking = false;
                        
                    }
                    //when out of mana
                    if (mana < 1)
                    {
                        vie = vie - currentEnemy[enemyIdentity].dmg;
                        srand(time(NULL));
                        mana = std::rand() % 15;
                        RemplirBarre(NB_SPELLS_BAR, nb_alea, NB_SPELLS, spellBar, listSpell, window);
                        spellsInBar = 4;
                    }
                    //when there is no spell in the bar
                    if (spellsInBar == 0)
                    {
                        srand(time(NULL));
                        RemplirBarre(NB_SPELLS_BAR, nb_alea, NB_SPELLS, spellBar, listSpell, window);
                        spellsInBar = 4;
                    }
                    if (vie < 1)
                    {
                       //for the roguelike future improvement
                       //vie = 100;                      
                       // coins = coins + enemyCount * 10;
                       // enemyCount = 0;
                       window.draw(gameOver);
                       //return EXIT_SUCCESS;
                        
                    }
                    
                    
                    
                }
               // if (game == false && title == false)
               // {
               //     titlePage.setTexture(titleOver_tex);
               //     window.draw(titlePage);
               // }
               

                // Draw the string
                //window.draw(text);

                // Update the window
                window.display();

            
        
        
    }    
    return EXIT_SUCCESS;
}

//this is the function that place the spells in your spellbar
void RemplirBarre(const int NB_SORTS_BARRE, int& nb_alea, const int NB_SORTS, Sort  barreDeSorts[4], Sort  listSort[6], sf::RenderWindow& window)
{
    for (int sortIndex = 0; sortIndex < NB_SORTS_BARRE; ++sortIndex)
    {

        nb_alea = std::rand() % NB_SORTS;
        barreDeSorts[sortIndex] = listSort[nb_alea];
        std::cout << barreDeSorts[sortIndex].name << std::endl;        
        barreDeSorts[sortIndex].img.setPosition(sf::Vector2f(sortIndex * DECALAGE_SORT_X, window.getSize().y - 150));

    }
}
