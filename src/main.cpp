#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

#include "GameObjects/Action.h"

#define gameAction "Time To Fight"
const char* const_idlePath = "../resource/Samurai/idle.png";
const char* const_runPath = "../resource/Samurai/Run.png";
const char* const_jumpPath = "../resource/Samurai/Jump.png";
const char* const_walkPath = "../resource/Samurai/Walk.png";
const char* const_attack_3Path = "../resource/Samurai/attack_3.png";
const char* const_attack_2Path = "../resource/Samurai/attack_2.png";
const char* const_attack_1Path = "../resource/Samurai/attack_1.png";
const char* const_hurtPath = "../resource/Samurai/Hurt.png";
const char* const_deadPath = "../resource/Samurai/dead.png";


// number of action frame
const int const_idleFrame = 6;
const int const_runFrame = 8;
const int const_jumpFrame = 12;
const int const_walkFrame = 8;
const int const_attack_3 = 3;
const int const_attack_2 = 4;
const int const_attack_1 = 6;
const int const_hurt = 2;
const int const_dead = 3;

void init(sf::Sprite& character , bool isIdle = true);
void animationCallbackFunction();


int main()
{
    sf::RenderWindow window(sf::VideoMode(800 , 600) , gameAction);

    Action idle = Action(const_idlePath , const_idleFrame , 0.2f , animationCallbackFunction);
    Action walk = Action(const_walkPath , const_walkFrame , 0.2f , animationCallbackFunction);
    Action attack_1 = Action(const_attack_1Path , const_attack_1 , 0.2f , animationCallbackFunction);
    Action attack_2 = Action(const_attack_2Path , const_attack_2 , 0.2f , animationCallbackFunction);
    Action attack_3 = Action(const_attack_3Path , const_attack_3 , 0.2f , animationCallbackFunction);

    sf::Sprite character;
    character.setPosition(sf::Vector2f(100.0f , 100.0f));
    bool isIdle = true;
    bool isWalk = false;
    bool isAttack_1 = false;
    bool isAttack_2 = false;
    bool isAttack_3 = false;

    init(character , idle);

    sf::Clock clock;
    float frameTime = 0.2f;

}

void init(sf::Sprite& character , Action& firstAction)
{
    character.setTexture(firstAction.getTexture());
    character.setTextureRect(firstAction.getCurrentFrameRect());
}

// int main()
// {
//     // Tạo cửa sổ
//     sf::RenderWindow window(sf::VideoMode(800, 600), "2D Animation");

//     // Tải sprite sheet (giả sử là hình ảnh 4x4 với mỗi frame có kích thước 128x128)
//     sf::Texture texture1;
//     sf::Texture texture2;
//     sf::Texture walk;
//     if (!texture1.loadFromFile("resource/Samurai/Attack_1.png") ||
//         !texture2.loadFromFile("resource/Samurai/Attack_2.png") ||
//         !walk.loadFromFile("resource/Samurai/Walk.png")) {
//         return -1;  // Không thể tải hình ảnh
//     }

//     // Tạo sprite với texture mặc định là "walk"
//     sf::Sprite sprite(walk);
//     sprite.setPosition(100, 100);
    
//     // Biến kiểm tra texture hiện tại và frame số
//     bool isUsingAttackAnimation = false;
//     int frameWidth = 128;
//     int frameHeight = 128;
//     int currentFrame = 0;
//     int frameNumber = 8;  // Số lượng frame cho "walk" mặc định là 8

//     sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));

//     // Thời gian để thay đổi frame (fps)
//     sf::Clock clock;
//     float frameTime = 0.2f;  // Thay đổi frame sau mỗi 0.2 giây
//     clock.restart();

//     while (window.isOpen())
//     {
//         sf::Time deltaTime = clock.getElapsedTime();

//         // Xử lý sự kiện đóng cửa sổ
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();

//             // Kiểm tra nếu nhấn phím Space để đổi sang animation tấn công
//             if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
//             {
//                 // Đổi texture giữa `texture1` và `texture2` khi nhấn phím Space
//                 if (!isUsingAttackAnimation || sprite.getTexture() == &walk) {
//                     sprite.setTexture(texture1);
//                     frameNumber = 6;  // Số lượng frame của `texture1` là 6
//                     currentFrame = 0;
//                 }
//                 else if (sprite.getTexture() == &texture1) {
//                     sprite.setTexture(texture2);
//                     frameNumber = 4;  // Số lượng frame của `texture2` là 4
//                     currentFrame = 0;
//                 }

//                 isUsingAttackAnimation = true;
//             }
//         }

//         // Cập nhật frame
//         if (deltaTime.asSeconds() > frameTime) {
//             currentFrame++;
//             if (currentFrame >= frameNumber) {
//                 // Nếu hoạt ảnh tấn công kết thúc, chuyển về "walk"
//                 if (isUsingAttackAnimation) {
//                     sprite.setTexture(walk);
//                     frameNumber = 8;  // Số lượng frame cho "walk"
//                     isUsingAttackAnimation = false;
//                 }
//                 currentFrame = 0;
//             }

//             // Cập nhật texture rectangle để lấy đúng frame
//             sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
//             clock.restart();
//         }

//         // Vẽ sprite
//         window.clear();
//         window.draw(sprite);
//         window.display();
//     }

//     return 0;
// }
