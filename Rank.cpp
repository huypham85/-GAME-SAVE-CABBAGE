#include "Rank.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
Rank::Rank()
{
	currentTime = 0;
}

Rank::~Rank()
{
}

void Rank::Exit()
{
}

void Rank::Pause()
{
}

void Rank::Resume()
{
}

void Rank::Init()
{
    //highscore
    f = fopen("Highscore.bin", "a+");
    if (fread(highscore, sizeof(highscore), 1, f))
    {
        printf("ReadFile success!\n");
    }
    else printf("ErrorRFile");
    fclose(f);
    for (int i = 1; i <= 5; i++) {
        printf("%d ", highscore[i]);
    }
    printf("\n");
	// background
	texture.loadFromFile("Pink.png");
	sprite.setTexture(texture);
	sprite.setScale(13.0f, 13.0f);
    titleTex.loadFromFile("HighScore.png");
    title.setTexture(titleTex);
    title.setScale(0.8f, 0.8f);
    title.setPosition(200, 60);

    // button
    button = new GameButton();
    buttonTex.loadFromFile("Back.png");
    button->setTexture(buttonTex);
    button->setPosition(0.0f, 0.0f);
    BackPos = button->getPosition();
    button->setScale(3.0f, 3.0f);
    button->SetOnClick([]() {
        State_Machine::GetInstance()->PopState();
        });

    // rank frame
    rank1Tex.loadFromFile("Rank1.png");
    rank2Tex.loadFromFile("Rank2.png");
    rank3Tex.loadFromFile("Rank3.png");
    rank4Tex.loadFromFile("Rank.png");
    rank5Tex.loadFromFile("Rank.png");
    rank1Sprite.setTexture(rank1Tex);
    rank2Sprite.setTexture(rank2Tex);
    rank3Sprite.setTexture(rank3Tex);
    rank4Sprite.setTexture(rank4Tex);
    rank5Sprite.setTexture(rank5Tex);
    rank1Sprite.setPosition(200, 250);
    rank2Sprite.setPosition(200, 350);
    rank3Sprite.setPosition(200, 450);
    rank4Sprite.setPosition(200, 550);
    rank5Sprite.setPosition(200, 650);
    rank1Sprite.setScale(0.5, 0.5);
    rank2Sprite.setScale(0.5, 0.5);
    rank3Sprite.setScale(0.5, 0.5);
    rank4Sprite.setScale(0.5, 0.5);
    rank5Sprite.setScale(0.5, 0.5);

    // init UI
    font.loadFromFile("Intro.ttf");
    ui1Text.setFont(font);
    ui1Text.setCharacterSize(45);
    ui1Text.setFillColor(Color::Red);
    stringstream ss;
    ss << highscore[1];
    ui1Text.setString(ss.str());
    ui1Text.setPosition(370.0f, 270.0f);
    ui2Text.setFont(font);
    ui2Text.setCharacterSize(45);
    ui2Text.setFillColor(Color::Red);
    stringstream ss2;
    ss2 << highscore[2];
    ui2Text.setString(ss2.str());
    ui2Text.setPosition(370.0f, 370.0f);
    ui3Text.setFont(font);
    ui3Text.setCharacterSize(45);
    ui3Text.setFillColor(Color::Red);
    stringstream ss3;
    ss3 << highscore[3];
    ui3Text.setString(ss3.str());
    ui3Text.setPosition(370.0f, 470.0f);
    ui4Text.setFont(font);
    ui4Text.setCharacterSize(45);
    ui4Text.setFillColor(Color::Red);
    stringstream ss4;
    ss4 << highscore[4];
    ui4Text.setString(ss4.str());
    ui4Text.setPosition(370.0f, 570.0f);
    ui5Text.setFont(font);
    ui5Text.setCharacterSize(45);
    ui5Text.setFillColor(Color::Red);
    stringstream ss5;
    ss5 << highscore[5];
    ui5Text.setString(ss5.str());
    ui5Text.setPosition(250.0f, 650.0f);
}

void Rank::Update(const float& deltaTime)
{
    button->CatchEvent(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y, BackPos.x, BackPos.y, "Back", window);
    button->Update(deltaTime);
}

void Rank::Draw(RenderTarget* Target)
{
    Target->draw(sprite);
    Target->draw(*button);
    Target->draw(title);
    Target->draw(rank1Sprite);
    Target->draw(rank2Sprite);
    Target->draw(rank3Sprite);
    Target->draw(rank4Sprite);
    //Target->draw(rank5Sprite);
    Target->draw(ui1Text);
    Target->draw(ui2Text);
    Target->draw(ui3Text);
    Target->draw(ui4Text);
    button->Draw(Target);
   // Target->draw(ui5Text);
}
