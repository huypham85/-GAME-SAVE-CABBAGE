#include "EndGame.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
using namespace std;
EndGame::EndGame()
{
	currentTime = 0;
	//highscore[0] = 2;
	highscore[1] = 1;
	highscore[2] = 1;
	highscore[3] = 1;
	highscore[4] = 1;
	highscore[5] = 1;
}

EndGame::~EndGame()
{
}

void EndGame::Exit()
{
}

void EndGame::Pause()
{
}

void EndGame::Resume()
{
}

void EndGame::Init()
{
	// background
	texture.loadFromFile("EndGame_background.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 634, 800, 800));
	//sprite.setScale(13.0f, 13.0f);
	deadTex.loadFromFile("dead_cabbage.png");
	deadSprite.setTexture(deadTex);
	deadSprite.setPosition(500, 640);
	deadSprite.setScale(4, 4);

	// highscore
	f = fopen("Highscore.bin", "a+");
	if (fread(highscore, sizeof(highscore), 1, f))
	{
		printf("ReadFile success!\n");
	}
	else printf("ErrorRFile");
	fclose(f);

	currentPoint = player.getPoints();
	for (int i = 4; i >= 1; i--) {
		if (highscore[i] < currentPoint) {
			highscore[i] = currentPoint;
			break;
		}
	}
	for (int i = 1; i <= 5; i++) {
		printf("%d ", highscore[i]);
	}
	printf("\n");
	sort(highscore + 1, highscore + 5 , greater<unsigned>());
	
	f = fopen("Highscore.bin", "w+");
	if (fwrite(highscore, sizeof(highscore), 1, f))
	{
		printf("WriteFile success!\n");
	}
	else printf("ErrorWFile"); fwrite(highscore, sizeof(highscore), 1, f);
	fclose(f);
	
	//init UI
	font.loadFromFile("GameFont.ttf");
	uiText.setFont(font);
	uiText.setCharacterSize(70);
	uiText.setFillColor(Color::Red);
	stringstream ss;
	ss << "SCORES " << endl
		<< "      " << this->player.getPoints();
	uiText.setString(ss.str());
	uiText.setPosition(280.0f, 110.0f);

	button = new GameButton();
	printf("state EndGame is created\n");
	buttonTex.loadFromFile("RestartBtn.png");
	button->setTexture(buttonTex);
	button->setPosition(350.0f, 600.0f);
	ReplayPos = button->getPosition();
	button->setScale(0.5f,0.5f);
	button->SetOnClick([]() {
		State_Machine::GetInstance()->PopState();
		State_Machine::GetInstance()->PopState();
		isReplay = true;
		});

	rankButton = new GameButton();
	rankButtonTex.loadFromFile("HighscoreBtn.png");
	rankButton->setTexture(rankButtonTex);
	rankButton->setPosition(350.0f, 450.0f);
	rankPos = rankButton->getPosition();
	rankButton->setScale(0.5f, 0.5f);
	rankButton->SetOnClick([]() {
		State_Machine::GetInstance()->ChangeState(StateTypes::STATE_Rank);
		});
}

void EndGame::Update(const float& deltaTime)
{
	currentTime += deltaTime;
	button->CatchEvent(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y, ReplayPos.x, ReplayPos.y, "Restart", window);
	button->Update(deltaTime);
	rankButton->CatchEvent(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y, rankPos.x, rankPos.y, "Highscore", window);
	rankButton->Update(deltaTime);
	if (isReplay == true) {
		//printf("point was reset\n");
		player.setPoint(0);
	}
}

void EndGame::Draw(RenderTarget* Target)
{
	Target->draw(sprite);
	Target->draw(uiText);
	Target->draw(*button);
	Target->draw(*rankButton);
	button->Draw(Target);
	rankButton->Draw(Target);
	Target->draw(deadSprite);
}
bool EndGame::isReplay = false;

