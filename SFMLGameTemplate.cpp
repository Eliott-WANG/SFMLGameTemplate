#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <iostream>

using namespace std;
/*
Creation de 4 sorts aleatoires
Cliquer : executer le sort et le supprimer de la barre de sort
Lorsque le joueur passe ou qu'il n'y a plus de sort dans la barre, les sorts restants sont supprimes et 4 nouveaux sorts sont piochés
.

*/

struct Sort
{
    int dmg;
    int costMana;
    sf::Sprite img;
    string name;
    bool isVisible = true;
};

struct Enemies
{
    int hp;
    int resistance;
    int dmg;
    

};
void RemplirBarre(const int NB_SORTS_BARRE, int& nb_alea, const int NB_SORTS, Sort  barreDeSorts[4], Sort  listSort[6], sf::RenderWindow& window);
const int DECALAGE_SORT_X = 150;
int main()
{
    int position = 0;
    int currentPlace = 1;
    bool title = true;
    bool game = false;
    int PA = 8;
    int vie = 100;
    int enemyPv = 10;
    int resistance = 0;
    int enemyCompteur = 0;
    srand(time(NULL));
    int nb_alea = std::rand() % 3;
    int enemyIdentity = nb_alea;
    const int NB_SORTS_BARRE = 4;
    const int NB_SORTS = 6;
    const int NB_ENEMIES = 10;
    Sort barreDeSorts[NB_SORTS_BARRE];
    bool cliking = true;
    int dmg[6];
    dmg[0] = 12;
    dmg[1] = 20;
    dmg[2] = 40;
    dmg[3] = 36;
    dmg[4] = 20;
    dmg[5] = 0;
    char textPA = PA;
    int coins = 0;
    Sort listSort[NB_SORTS];
    Enemies currentEnemy[NB_ENEMIES];
    int sortsEnBarre = 4;
    



    // Create the main window
    sf::RenderWindow window(sf::VideoMode(816, 624), "SFML window");

    // Load a sprite to display
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
    if (!enemy_tex.loadFromFile("Res/Walvak/100521.png"))
        return EXIT_FAILURE;

    sf::IntRect frameSprite;
    

    titlePage.setTexture(titlePage_tex);
    sl1.setTexture(sl1_tex);
    enemy.setTexture(enemy_tex);
    enemy.setTextureRect(frameSprite);
    

    listSort[0].costMana = 1;
    listSort[0].dmg = 1;
    listSort[0].img = sf::Sprite(A_tex);
    listSort[0].name = "A";
    
    listSort[1].costMana = 2;
    listSort[1].dmg = 2;
    listSort[1].img = sf::Sprite(B_tex);
    listSort[1].name = "B";

    listSort[2].costMana = 3;
    listSort[2].dmg = 4;
    listSort[2].img = sf::Sprite(C_tex);
    listSort[2].name = "C";

    listSort[3].costMana = 3;
    listSort[3].dmg = 1;
    listSort[3].img = sf::Sprite(D_tex);
    listSort[3].name = "D";

    listSort[4].costMana = 4;
    listSort[4].dmg = 5;
    listSort[4].img = sf::Sprite(E_tex);
    listSort[4].name = "E";

    listSort[5].costMana = 5;
    listSort[5].dmg = 3;
    listSort[5].img = sf::Sprite(F_tex);
    listSort[5].name = "F";

    currentEnemy[0].hp = 10;
    currentEnemy[0].resistance = 0;
    currentEnemy[0].dmg = 4;
    
    currentEnemy[1].hp = 7;
    currentEnemy[1].resistance = 0;
    currentEnemy[1].dmg = 3;
    
    currentEnemy[2].hp = 15;
    currentEnemy[2].resistance = 0;
    currentEnemy[2].dmg = 2;
    
    currentEnemy[10].hp = 120;
    currentEnemy[10].resistance = 1;
    currentEnemy[10].dmg = 6;

    //mickey.setTextureRect(frameSprite);


    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("Res/Snacko Trial.otf"))
        return EXIT_FAILURE;
    sf::Text text(textPA, font, 100);
    text.setPosition(sf::Vector2f(0, 0));


    // Load a music to play
    //sf::Music music;
    //if (!music.openFromFile("Res/2-19. Calamari Inkantation.mp3"))
    //    return EXIT_FAILURE;

    // Play the music
    //music.play();
    sf::Clock clock;

    // Start the game loop
    RemplirBarre(NB_SORTS_BARRE, nb_alea, NB_SORTS, barreDeSorts, listSort, window);
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
                        title = false;
                        game = true;
                    }
                }
                if (userevent.type == sf::Event::MouseButtonPressed && game == true)
                {
                    cliking = true;
                }
                    
                

                // Close window: exit
                if (userevent.type == sf::Event::Closed)
                    window.close();



            }
            if (clock.getElapsedTime().asSeconds() >= 0.1f)
            {



            }
            
            
            
            
            
            
            //text.move(sf::Vector2f(0.0, -0.1));
                sf::Vector2f textposition = text.getPosition();
                //cout << textposition.x << "  " << textposition.y << endl;
                //sf::Vector2i mouseposition = sf::Mouse::getPosition(window);
                /*cout << mouseposition.x << "  " << mouseposition.y << endl;*/
                
                if (clock.getElapsedTime().asSeconds() > 3)
                {
                    
                    clock.restart();
                }


                // Draw the sprite
                if (title)
                {
                    window.draw(titlePage);
                    window.draw(jouer);
                }
                if (game)
                {
                    
                    if (PA > 0)
                    {
                        
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
                        if (enemyIdentity == 10)
                        {
                            frameSprite.left = 1323.f;
                            frameSprite.top = 889.f;
                            frameSprite.width = 465.f;
                            frameSprite.height = 415.f;
                            enemy.setPosition(sf::Vector2f(140, 70));
                            enemy.setTextureRect(frameSprite);
                        }
                        if (cliking)
                        {
                            if (mousePosition.y < window.getSize().y - (150 - 128) && mousePosition.y > window.getSize().y - 150)
                            {
                               
                                for (int sortIndex = 0; sortIndex < NB_SORTS_BARRE; ++sortIndex)
                                {                                
                                    if (mousePosition.x > barreDeSorts[sortIndex].img.getPosition().x && mousePosition.x < barreDeSorts[sortIndex].img.getPosition().x + 128)
                                    {
                                        if (!barreDeSorts[sortIndex].isVisible) continue;                                       
                                        enemyPv = enemyPv - (barreDeSorts[sortIndex].dmg - currentEnemy[enemyIdentity].resistance);
                                        
                                        std::cout << vie << "ult" << std::endl;
                                        PA = PA - barreDeSorts[sortIndex].costMana;
                                        std::cout << PA << std::endl;
                                        std::cout << enemyPv << "hp" << std::endl;
                                        barreDeSorts[sortIndex].isVisible = false;
                                        sortsEnBarre -= 1;
                                    }

                                }
                            }
                            else if (mousePosition.y < 500 + (37*2) && mousePosition.y > 499 && mousePosition.x < 650 + (37*2) && mousePosition.y > 649)
                            {
                                vie = vie - currentEnemy[enemyIdentity].dmg;
                                srand(time(NULL));
                                PA = std::rand() % 15;
                                RemplirBarre(NB_SORTS_BARRE, nb_alea, NB_SORTS, barreDeSorts, listSort, window);
                                sortsEnBarre = 4;
                            }
                        }
                        if (enemyPv < 1)
                        {
                            currentPlace = currentPlace + 1;
                            
                            if (enemyCompteur < 19)
                            {
                                srand(time(NULL));
                                nb_alea = std::rand() % 3;
                                enemyIdentity = nb_alea;
                                enemyPv = currentEnemy[enemyIdentity].hp;
                                enemyCompteur = enemyCompteur + 1;
                                std::cout << enemyCompteur << "oi" << std::endl;
                                srand(time(NULL));
                                PA = PA + std::rand() % 5;
                            }
                            else
                            {
                                enemyIdentity = 10;
                                enemyPv = currentEnemy[enemyIdentity].hp;
                            }

                        }
                        window.draw(sl1);
                        window.draw(enemy);
                        window.draw(passer);
                        for (int sortIndex = 0; sortIndex < NB_SORTS_BARRE; ++sortIndex)
                        {
                            if (!barreDeSorts[sortIndex].isVisible) continue;
                            window.draw(barreDeSorts[sortIndex].img);

                        }
                        cliking = false;
                        
                    }
                    if (PA < 1)
                    {
                        vie = vie - currentEnemy[enemyIdentity].dmg;
                        srand(time(NULL));
                        PA = std::rand() % 15;
                        RemplirBarre(NB_SORTS_BARRE, nb_alea, NB_SORTS, barreDeSorts, listSort, window);
                        sortsEnBarre = 4;
                    }
                    if (sortsEnBarre == 0)
                    {
                        srand(time(NULL));
                        RemplirBarre(NB_SORTS_BARRE, nb_alea, NB_SORTS, barreDeSorts, listSort, window);
                        sortsEnBarre = 4;
                    }
                    if (vie < 1)
                    {
                        vie = 100;
                        game = true;
                        coins = coins + enemyCompteur * 10;
                        enemyCompteur = 0;
                        
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
