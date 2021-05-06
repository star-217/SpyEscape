// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"
#include "GameScene/SelectScene.hpp"

int GameMain::time = 0;

#include <fstream>
#define MAZE_WIDTH 32
#define MAZE_HEIGHT 18
/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));

	//GameTimer.SetFPS(10);
	//int cells[MAZE_WIDTH][MAZE_HEIGHT];

	DefaultFont = GraphicsDevice.CreateDefaultFont();

	MediaManager.Attach(GraphicsDevice);

	
	bgm = MediaManager.CreateMediaFromFile(_T("bgm3.mp3"));
	bgm->Play();
	mission = MediaManager.CreateMediaFromFile(_T("mission.mp3"));
	bg = GraphicsDevice.CreateSpriteFromFile(_T("deza.png"));
	se = SoundDevice.CreateSoundFromFile(_T("nc86224.wav"));


	time = 60;
	flame = 0;

	skill = GraphicsDevice.CreateSpriteFromFile(_T("Image/skill.png"));

	change = Vector3(0, 0, 0);
	cl = Color(255, 255, 255);
	player_spd = 5.0f;
	tracker_spd = player_spd * 1.2f;
	player_state = 0;

	p_flame_x = 0.0f;
	p_flame_y = 0.0f;
	p_walk_flag = 0;

	tracker_flame_x = 0.0f;
	tracker_flame_y = 0.0f;
	attack_state = 0;

	tracker_state = 0;
	win_flame = 0;

	win_time = 0;
	lose_flame = 0;

	down_flame = 0;
	player_count = 0;

	b_alpha = 1.0f;

	a = 7;
	b = 11;
	skill_state = false;
	skill_time = 0.0f;
	skill_alpha = 1.0f;
	a_alpha = 1.0f;
	tracker_alpha = 1.0f;
	alpha_flag = false;
	fake_flag = false;
	abc = 0;
	invisible_state = 0;
	invisible_time = 0;
	invisible_alpha = 1.0f;
	randam_skil = 0;
	skil_time = 0;
	f = 0;
	black_flag = false;
	越前 = 0;

	attack_state = 0;
	stun_state = false;
	stun_time = 0;
	lose_time = 0;

	InputDevice.CreateGamePad(1);


	for (int i = 0; i < 2; i++) {
		randam[i] = 0;
	}

	newfont = GraphicsDevice.CreateSpriteFont(_T("georgia"), 50);

	wall = GraphicsDevice.CreateSpriteFromFile(_T("wall.png"));
	ton = GraphicsDevice.CreateSpriteFromFile(_T("ton.png"));

	floar = GraphicsDevice.CreateSpriteFromFile(_T("floar.png"));

	skil = MediaManager.CreateMediaFromFile(_T("Spotlight04-1.mp3"));


	fake = GraphicsDevice.CreateSpriteFromFile(_T("fake.png"));

	down = GraphicsDevice.CreateSpriteFromFile(_T("playerdown.png"));

	direc4 = 0;
	player = GraphicsDevice.CreateSpriteFromFile(_T("player3.png"));

	anime = 0;
	direc = 0;
	tracker = GraphicsDevice.CreateSpriteFromFile(_T("oni2.png"));

	oniwin = GraphicsDevice.CreateSpriteFromFile(_T("oniwin.png"));

	playerwin = GraphicsDevice.CreateSpriteFromFile(_T("playerwin.png"));
	isu = GraphicsDevice.CreateSpriteFromFile(_T("isu.png"));

	tracker_attack = GraphicsDevice.CreateSpriteFromFile(_T("punch.png"));

	lose = GraphicsDevice.CreateSpriteFromFile(_T("lose.png"));

	//マップデータ
	map_data_b[0] =  ("################################");
	map_data_b[1] =  ("#             $$               #");
	map_data_b[2] =  ("#   $ $   $$      $$   $$  $$  #");
	map_data_b[3] =  ("#  $$ $$          $$           #");
	map_data_b[4] =  ("#                              #");
	map_data_b[5] =  ("#  $$ $$  $  $  $    $   $$$$  #");
	map_data_b[6] =  ("#   $ $      $  $              #");
	map_data_b[7] =  ("#          $$$  $$$            #");
	map_data_b[8] =  ("#       $                $$$$  #");
	map_data_b[9] =  ("#   $$  $             $        #");
	map_data_b[10] = ("#   $$     $$$  $$$   $        #");
	map_data_b[11] = ("#            $  $        $ $   #");
	map_data_b[12] = ("#     $$     $  $       $$ $$  #");
	map_data_b[13] = ("#                   $$         #");
	map_data_b[14] = ("#   $$  $$              $$ $$  #");
	map_data_b[15] = ("#   $$  $$          $$   $ $   #");
	map_data_b[16] = ("#              $$              #");
	map_data_b[17] = ("################################");

	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < map_data_b[y].size(); x++) {
			dist[y].push_back(0);
			dist_A[y].push_back(0);
			dist2[y].push_back(0);
			dist3[y].push_back(0);
			dist4[y].push_back(0);
			dist5[y].push_back(0);
			dist6[y].push_back(0);
			dist_player[y].push_back(0);
			dist_AI[y].push_back(0);
		}
	}

	tracker_pos = Vector3(1500, 800, 0);


	for (int i = 0; i < 4; i++) {
		mx_k[i] = 0;
		my_k[i] = 0;
		mx_i[i] = 0;
		my_i[i] = 0;
		mx_h[i] = 0;
		my_h[i] = 0;
		mx_g[i] = 0;
		my_g[i] = 0;
		mx_o[i] = 0;
		my_o[i] = 0;
		mx_p[i] = 0;
		my_p[i] = 0;

	}

	direc5 = 0;
	direc6 = 0;

	k_count = 10;
	j_count = 10;
	h_count = 10;
	g_count = 10;
	o_count = 10;
	p_count = 10;

	j = 0;
	h = 0;
	g = 0;
	k = 0;
	o = 0;
	p = 0;
	fake_speed[0] = Vector3(0, -1, 0);
	fake_speed[1] = Vector3(0, 1, 0);
	fake_speed[2] = Vector3(1, 0, 0);
	fake_speed[3] = Vector3(-1, 0, 0);
	fake_dir[0] = 3;
	fake_dir[1]	= 0;
	fake_dir[2]	= 2;
	fake_dir[3]	= 1;



	fake_stop_count[0] = 16;
	fake_stop_count[1] = 8;
	fake_stop_count[2] = 22;
	fake_stop_count[3] = 14;
	fake_stop_count[4] = 28;
	fake_stop_count[5] = 16;


	int select = SelectScene::GetSelect();

	Vector3 start_Pos[] = { Vector3(150,400,0),Vector3(800,100,0),Vector3(1250,150,0),Vector3(850, 700, 0),Vector3(50, 750, 0),Vector3(1500, 200, 0),Vector3(1500, 500, 0) };

	//選択シーンでの選択によっての分岐
	if (select == 0) {
		player_pos = start_Pos[0];
		fake_pos = start_Pos[1];
		fake2_pos = start_Pos[2];
		fake3_pos = start_Pos[3];
		fake4_pos = start_Pos[4];
		fake5_pos = start_Pos[5];
		fake6_pos = start_Pos[6];
	}
	if (select == 1) {
		player_pos = start_Pos[1];
		fake_pos = start_Pos[2];
		fake2_pos = start_Pos[0];
		fake3_pos = start_Pos[3];
		fake4_pos = start_Pos[4];
		fake5_pos = start_Pos[5];
		fake6_pos = start_Pos[6];
	}
	if (select == 2) {
		player_pos = start_Pos[2];
		fake_pos = start_Pos[0];
		fake2_pos = start_Pos[1];
		fake3_pos = start_Pos[3];
		fake4_pos = start_Pos[4];
		fake5_pos = start_Pos[5];
		fake6_pos = start_Pos[6];
	}
	if (select == 3) {
		player_pos = start_Pos[3];
		fake_pos = start_Pos[0];
		fake2_pos = start_Pos[1];
		fake3_pos = start_Pos[2];
		fake4_pos = start_Pos[4];
		fake5_pos = start_Pos[5];
		fake6_pos = start_Pos[6];
	}
	if (select == 4) {
		player_pos = start_Pos[4];
		fake_pos = start_Pos[0];
		fake2_pos = start_Pos[1];
		fake3_pos = start_Pos[3];
		fake4_pos = start_Pos[2];
		fake5_pos = start_Pos[5];
		fake6_pos = start_Pos[6];
	}
	if (select == 5) {
		player_pos = start_Pos[5];
		fake_pos = start_Pos[0];
		fake2_pos = start_Pos[1];
		fake3_pos = start_Pos[3];
		fake4_pos = start_Pos[4];
		fake5_pos = start_Pos[2];
		fake6_pos = start_Pos[6];
	}
	if (select == 6) {
		player_pos = start_Pos[6];
		fake_pos = start_Pos[0];
		fake2_pos = start_Pos[1];
		fake3_pos = start_Pos[3];
		fake4_pos = start_Pos[4];
		fake5_pos = start_Pos[5];
		fake6_pos = start_Pos[2];
	}
	

	
	prev_mx = -1;
	prev_my = -1;


	InputDevice.CreateGamePad(2);
	pad2_direction = 0;

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here

}



int GameMain::Update()
{



	Player();
	Tracker();
	AI();
	Fake(fake_pos,k_count,k,direc2,mx_k,my_k,dist2,fake_stop_count[0]);
	Fake(fake2_pos, j_count, j, direc3, mx_i, my_i, dist_AI, fake_stop_count[1]);
	Fake(fake3_pos, h_count, h, direc5, mx_h, my_h, dist3, fake_stop_count[2]);
	Fake(fake4_pos, g_count, g, direc6, mx_g, my_g, dist4, fake_stop_count[3]);
	Fake(fake5_pos, p_count, p, direc7, mx_p, my_p, dist5, fake_stop_count[4]);
	Fake(fake6_pos, o_count, o, direc8, mx_o, my_o, dist6, fake_stop_count[5]);



	if (stun_state == true) {
		if (fake_flag = true && tracker_alpha >= 255) {
			fake_flag = false;
		}
		if (fake_flag = false && tracker_alpha <= 0) {
			fake_flag = true;
		}
		if (fake_flag) {
			tracker_alpha += 20;
		}
		else {
			tracker_alpha -= 20;
		}
	}
	else {
		tracker_alpha = 1.0f;
	}

	if (stun_state == true) {
		stun_time += 1.0f;
		if (stun_time >= 120.0f) {
	
			stun_time = 0.0f;
			stun_state = false;
		}
	}


	if (tracker_state == 0) {
		flame++;
		if (flame == 60) {
			time -= 1;
			flame = 0;
			if (time == 0) {

				tracker_state = 2;
			}
		}
	}

	if (time == 20) {
		bgm->Stop();
		mission->Play();
		
	}

	if (time <= 15) {
		a_alpha -= 0.02f;
	}

	if (a_alpha <= 0.0f) {
		a_alpha = 0.0f;
	}

	if (time <= 30) {
		b_alpha -= 0.02f;
	}

	if (b_alpha <= 0.0f) {
		b_alpha = 0.0f;
	}

	if (time == 15) {
		tracker_spd = player_spd * 1.5;
	}

	if (lose_time >= 180) {
		return GAME_SCENE(new clearScene);
	}

	//鬼と逃げる人の当たり判定

	KeyboardBuffer key_buffer = Keyboard->GetBuffer();
	GamePadBuffer pad_1_buffer = GamePad(1)->GetBuffer();



	if (attack_state == 1)
	{
		if (invisible_state == false) {

			if (player_pos.x + 35 < tracker_pos.x + 15 || player_pos.x + 15 > tracker_pos.x + 35 ||
				player_pos.y + 40 < tracker_pos.y + 10 || player_pos.y + 10 > tracker_pos.y + 40)
			{
			}
			else if (time >= 0)
			{
				tracker_state = 1;
				player_state = 1;
			}
		}
	}

	if (win_time >= 180)
	{
		return GAME_SCENE(new resultScene);
	}


	if (tracker_state == 0) {
		anime += 1.0f;
	}
	else {
		anime = 1;
	}
	if (anime >= 40) {
		anime = 0;
	}

	AI_count++;

	return 0;
}




void GameMain::Tracker()
{
	KeyboardState key = Keyboard->GetState();
	KeyboardBuffer key_buf = Keyboard->GetBuffer();
	GamePadState pad_1 = GamePad(0)->GetState();
	GamePadState pad_2 = GamePad(1)->GetState();

	//パッドの入力が強い方向にキャラが動くように（斜め移動の禁止）
	pad_direction = 0;
	if (pad_1.X != 0 || pad_1.Y != 0) {
		float axis_x = Math_Abs(pad_1.X);
		float axis_y = Math_Abs(pad_1.Y);
		if (axis_x > axis_y) {
			if (pad_1.X > 0) {
				pad_direction = 6;
			}
			else if (pad_1.X < 0) {
				pad_direction = 4;
			}
		}
		else {
			if (pad_1.Y > 0) {
				pad_direction = 2;
			}
			else if (pad_1.Y < 0) {
				pad_direction = 8;
			}
		}
	}

	//キャラの座標のブロック分け
	int nx = (int)((tracker_pos.x + 50) / 50);
	int ny = (int)((tracker_pos.y + 50) / 50);

	//キャラの移動、移動制限
	if (stun_state == false) {
		if (tracker_state == 0) {
			if (key.IsKeyDown(Keys_D) || pad_direction == 6) {
				tracker_pos.x += tracker_spd;
				direc4 = 2;


				int mx = (int)(tracker_pos.x / 50);
				int my = (int)(tracker_pos.y / 50);

				if (map_data_b[my][mx + 1] != ' ')
					tracker_pos.x = mx * 50;


				int py = (int)tracker_pos.y % 50;
				if (py != 0) {
					if (py < 10)
						tracker_pos.y = ((int)tracker_pos.y / 50 + 0) * 50;
					else if (py > 40)
						tracker_pos.y = ((int)tracker_pos.y / 50 + 1) * 50;
					else if (map_data_b[my + 1][mx + 1] != ' ')
						tracker_pos.x = mx * 50;


				}
			}

			else if (key.IsKeyDown(Keys_A) || pad_direction == 4) {
				tracker_pos.x -= tracker_spd;
				direc4 = 1;


				int mx = (int)(tracker_pos.x / 50);
				int my = (int)(tracker_pos.y / 50);

				if (map_data_b[my][mx] != ' ')
					tracker_pos.x = (mx + 1) * 50;


				int py = (int)tracker_pos.y % 50;
				if (py != 0) {
					if (py < 10)
						tracker_pos.y = ((int)tracker_pos.y / 50 + 0) * 50;
					else if (py > 40)
						tracker_pos.y = ((int)tracker_pos.y / 50 + 1) * 50;
					else if (map_data_b[my + 1][mx] != ' ')
						tracker_pos.x = (mx + 1) * 50;
				}
			}

			else if (key.IsKeyDown(Keys_S) || pad_direction == 2) {
				tracker_pos.y += tracker_spd;
				direc4 = 0;


				int mx = (int)(tracker_pos.x / 50);
				int my = (int)(tracker_pos.y / 50);

				if (map_data_b[my + 1][mx] != ' ')
					tracker_pos.y = my * 50;


				int px = (int)tracker_pos.x % 50;
				if (px != 0) {
					if (px < 10)
						tracker_pos.x = ((int)tracker_pos.x / 50 + 0) * 50;
					else if (px > 40)
						tracker_pos.x = ((int)tracker_pos.x / 50 + 1) * 50;
					else if (map_data_b[my + 1][mx + 1] != ' ')
						tracker_pos.y = my * 50;
				}
			}

			else if (key.IsKeyDown(Keys_W) || pad_direction == 8) {
				tracker_pos.y -= tracker_spd;
				direc4 = 3;


				int mx = (int)(tracker_pos.x / 50);
				int my = (int)(tracker_pos.y / 50);

				if (map_data_b[my][mx] != ' ')
					tracker_pos.y = (my + 1) * 50;


				int px = (int)tracker_pos.x % 50;
				if (px != 0) {
					if (px < 10)
						tracker_pos.x = ((int)tracker_pos.x / 50 + 0) * 50;
					else if (px > 40)
						tracker_pos.x = ((int)tracker_pos.x / 50 + 1) * 50;
					else if (map_data_b[my][mx + 1] != ' ')
						tracker_pos.y = (my + 1) * 50;
				}
			}
		}
	}





	int mx = (int)(tracker_pos.x / 50);
	int my = (int)(tracker_pos.y / 50);
	//脅威マップ
	if (mx != prev_mx || my != prev_my) {
		max = FLT_MIN;
		min = FLT_MAX;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < map_data_b[y].size(); x++) {
				if (map_data_b[y][x] == ' ') {
					dist[y][x] = Vector3_Distance(tracker_pos, Vector3(x * 50, y * 50, 0));

					if (max < dist[y][x])
					{
						max = dist[y][x];
					}
					if (min > dist[y][x])
					{
						min = dist[y][x];
					}
				}
				else {
					dist[y][x] = -1;


				}
			}
		}

		normal = max - min;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < map_data_b[y].size(); x++) {
				if (dist[y][x] >= 0)
					dist[y][x] = ((dist[y][x] - min) / normal);
				else
					dist[y][x] = 0;
			}
		}



		prev_mx = mx;
		prev_my = my;
	}


	for (int i = 3; i > 0; i--) {
		dist[my_k[i]][mx_k[i]] = 0;
		dist_player[my_k[i]][mx_k[i]] = 0;
	}
	for (int i = 3; i > 0; i--) {
		mx_k[i] = mx_k[i - 1];
		my_k[i] = my_k[i - 1];
	}


	//アニメーション
	if (tracker_state == 1)
	{
		win_flame += 0.8f;
		down_flame += 0.8f;
		win_time++;
	}

	if (lose_flame > 30)
	{
		lose_flame = 0;
	}

	if (win_flame >= 50)
	{
		win_flame = 0;
	}

	if (tracker_state == 2) {
		win_flame += 0.8f;
		lose_flame += 0.5f;
		lose_time++;
	}

	if (skil_time <= 0) {
		skil_time = 0;
	}







}



void GameMain::Player()
{
	KeyboardState  key = Keyboard->GetState();
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();
	GamePadState  pad_2 = GamePad(1)->GetState();
	GamePadBuffer pad_buffer = GamePad(1)->GetBuffer();
	GamePadBuffer pad_buffer2 = GamePad(0)->GetBuffer();



	if (pad2_direction == 0) {
		if (pad_2.X != 0 || pad_2.Y != 0) {
			int mx = (int)(player_pos.x / 50);
			int my = (int)(player_pos.y / 50);
			float axis_x = Math_Abs(pad_2.X);
			float axis_y = Math_Abs(pad_2.Y);
			if (axis_x > axis_y) {
				if (pad_2.X > 0) {
					if (map_data_b[my][mx + 1] == ' ') {
						pad2_direction = 6;
						player_count = 0;
					}
				}
				else if (pad_2.X < 0) {
					if (map_data_b[my][mx - 1] == ' ') {
						pad2_direction = 4;
						player_count = 0;
					}
				}
			}
			else {
				if (pad_2.Y > 0) {
					if (map_data_b[my + 1][mx] == ' ') {
						pad2_direction = 2;
						player_count = 0;
					}
				}
				else if (pad_2.Y < 0) {
					if (map_data_b[my - 1][mx] == ' ') {
						pad2_direction = 8;
						player_count = 0;
					}
				}
			}
		}
	}

	if (pad2_direction == 0) {
		if (key.IsKeyDown(Keys_Right)|| key.IsKeyDown(Keys_Left) || key.IsKeyDown(Keys_Down) || key.IsKeyDown(Keys_Up)) {
			int mx = (int)(player_pos.x / 50);
			int my = (int)(player_pos.y / 50);
				if (key.IsKeyDown(Keys_Right)) {
					if (map_data_b[my][mx + 1] == ' ') {
						pad2_direction = 6;
						player_count = 0;
					}
				}
				else if (key.IsKeyDown(Keys_Left)) {
					if (map_data_b[my][mx - 1] == ' ') {
						pad2_direction = 4;
						player_count = 0;
					}
				}
				else if (key.IsKeyDown(Keys_Down)) {
					if (map_data_b[my + 1][mx] == ' ') {
						pad2_direction = 2;
						player_count = 0;
					}
				}
				else if (key.IsKeyDown(Keys_Up)) {
					if (map_data_b[my - 1][mx] == ' ') {
						pad2_direction = 8;
						player_count = 0;
					}
				}
			
		}
	}







	if (randam_skil != 4) {
		if (tracker_state == 0) {
			if ( pad2_direction == 6) {
				player_pos.x += player_spd;
				direc = 2;

				player_count += player_spd;

				if (player_count >= 50) {
					pad2_direction = 0;
				}
				
			}


		else if (pad2_direction == 4) {
			player_pos.x -= player_spd;
			direc = 1;

			player_count += player_spd;

			if (player_count >= 50) {
				pad2_direction = 0;
			}
		}

		else if (pad2_direction == 2) {
			player_pos.y += player_spd;
			direc = 0;

			player_count += player_spd;

			if (player_count >= 50) {
				pad2_direction = 0;
			}

		}

		else if (pad2_direction == 8) {
				player_pos.y -= player_spd;
				direc = 3;

				player_count += player_spd;

				if (player_count >= 50) {
					pad2_direction = 0;
				}
				
			}

			
		}
	}




	if (f < 5) {
		if (skil_time == 0) {
			if (key_buffer.IsPressed(Keys_L) || pad_buffer.IsPressed(GamePad_Button6)) {

				/*randam_skil += 1;*/
				skil->Play();
				randam_skil = MathHelper_Random(1, 5);
				for (int i = -1; i < f; i++) {
					if (randam[i] == randam_skil) {
						randam_skil = MathHelper_Random(1, 5);
						i = -1;
					}
				}

				randam[f] = randam_skil;
				f++;
				skil_time = 300;
			}
		}
	}

	skil_time--;
	//暗転化

	if (black_flag == false)
	{
		if (randam_skil == 1) {
			skill_state = true;
			alpha_flag = true;
			black_flag = true;
		}
		//}
	}


	if (skill_state == true)
	{
		skill_time += 1.0f;

		if (skill_time > 60.0f)
		{
			skill_alpha -= 0.008f;
		}

		if (skill_alpha < 0.0f)
		{
			skill_state = false;
			skill_time = 0.0f;
			skill_alpha = 1.0f;
		}
	}

	else if (skill_time < 0)
	{
		skill_state = false;
		skill_time = 0.0f;
		alpha_flag = false;
		skill_alpha = 1.0f;
	}

	//透明化

	if (abc == 0)
	{

		if (invisible_state == false)
		{	
			if (randam_skil == 2) {
				abc = 1;
				invisible_state = true;
			
			}
		}
	}


	if (invisible_state == true)
	{
		invisible_time += 1.0f;
		invisible_alpha += 20.0f;

		if (invisible_time >= 120.0f)
		{
			invisible_state = false;
			invisible_alpha = 1.0f;
			invisible_time = 0.0f;
		}

	}
	if (invisible_alpha >= 255.0f) {
		invisible_alpha = 255.0f;
	}

	//ダッシュ
	if (randam_skil == 3) {
		stun_state = true;
		randam_skil = 0;

	}
	


	//スタン
	if (randam_skil == 4) {
		越前 += 1;
		if (skil_time <= 180) {
			randam_skil = 0;
		}

	}
	//越前
	if (越前 == 1) {
		se->Play();

	}
	//カラー
	if (randam_skil == 5) {
		cl = Color(255, 0, 0);
	}




	//マップ
	int mx = player_pos.x / 50;
	int my = player_pos.y / 50;

	if (mx != prev_mx2 || my != prev_my2) {
		max2 = FLT_MIN;
		min2 = FLT_MAX;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < map_data_b[y].size(); x++) {
				if (map_data_b[y][x] == ' ') {
					dist_player[y][x] = Vector3_Distance(player_pos, Vector3(x * 50, y * 50, 0));

					if (max2 < dist_player[y][x])
					{
						max2 = dist_player[y][x];
					}
					if (min2 > dist_player[y][x])
					{
						min2 = dist_player[y][x];
					}
				}
				else {
					dist_player[y][x] = -1;
				}
			}
		}

		normal2 = max2 - min2;
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < map_data_b[y].size(); x++) {
				if (dist_player[y][x] >= 0)
					dist_player[y][x] = 1.0 - ((dist_player[y][x] - min2) / normal2);
				else
					dist_player[y][x] = 0;
			}
		}




		prev_mx2 = mx;
		prev_my2 = my;
	}

	for (int i = 3; i > 0; i--) {
		dist[my_i[i]][mx_i[i]] = 0;
		dist_player[my_i[i]][mx_i[i]] = 0;
	}
	for (int i = 3; i > 0; i--) {
		mx_i[i] = mx_i[i - 1];
		my_i[i] = my_i[i - 1];
	}



	// パンチ
	if (tracker_state == 0) {
		if (key_buffer.IsPressed(Keys_G) || pad_buffer2.IsPressed(GamePad_Button6))
		{
			attack_state = 1;
		}
	}

	if (attack_state == 1)
	{
		tracker_flame_x += 0.6f;
	}
	if (tracker_flame_x >= 20)
	{
		attack_state = 0;
		tracker_flame_x = 0;
	}


}

//プレイヤーのデコイたちのAI
void GameMain::Fake(Vector3& ai_pos, int& move_count, int& ai_pattern, float& dir, int old_pos_x[], int old_pos_y[], std::vector<float> ai_mapdata[],int& c)
{
	KeyboardState key = Keyboard->GetState();


	//キャラの場所のブロック分け
	int mx = (int)(ai_pos.x / 50);
	int my = (int)(ai_pos.y / 50);
	int prev_mx = 0;
	int prev_my = 0;

	float max = 0;


	if (move_count == 10) {

		ai_pattern = 0;

		if (randam_skil != 4) {
			if (tracker_state == 0) {
				if (time % c != 0) {
					if (ai_mapdata[my - 1][mx] > max) {
						max = ai_mapdata[my - 1][mx];
						ai_pattern = 1;
					}
					if (ai_mapdata[my + 1][mx] > max) {
						max = ai_mapdata[my + 1][mx];
						ai_pattern = 2;

					}

					if (ai_mapdata[my][mx + 1] > max) {
						max = ai_mapdata[my][mx + 1];
						ai_pattern = 3;

					}

					if (ai_mapdata[my][mx - 1] > max) {
						max = ai_mapdata[my][mx - 1];
						ai_pattern = 4;
					}

					if (ai_pattern != 0) {
						for (int i = 3; i > 0; i--) {
							dist[old_pos_y[i]][old_pos_x[i]] = 0;
							dist_player[old_pos_y[i]][old_pos_x[i]] = 0;
						}
						for (int i = 3; i > 0; i--) {
							old_pos_x[i] = old_pos_x[i - 1];
							old_pos_y[i] = old_pos_y[i - 1];
						}


						old_pos_x[0] = mx;
						old_pos_y[0] = my;


						move_count = 0;

					}
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (ai_pattern == i + 1) {
			ai_pos += fake_speed[i] * player_spd;
			dir = fake_dir[i];
			move_count++;
		}
	}

	// 鬼とデコイの当たり判定
	if (invisible_state == false) {
		if (attack_state == 1) {
			if (tracker_pos.x + 35 < ai_pos.x + 15 || tracker_pos.x + 15 > ai_pos.x + 35 ||
				tracker_pos.y + 40 < ai_pos.y + 10 || tracker_pos.y + 10 > ai_pos.y + 40) {
			}
			else if (time >= 0) {

				stun_state = true;
			}

		}
	}
}


void GameMain::AI()
{
	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < map_data_b[y].size(); x++) {
			if (dist2[y][x] >= 0)
				dist2[y][x] = dist_player[y][x] * 0.4 + dist[y][x] * 0.6;
			else
				dist2[y][x] = 0;
		}
	}

	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < map_data_b[y].size(); x++) {
			if (dist_AI[y][x] >= 0)
				dist_AI[y][x] = dist_player[y][x] * 0.5 + dist[y][x] * 0.5;
			else
				dist_AI[y][x] = 0;
		}
	}

	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < map_data_b[y].size(); x++) {
			if (dist3[y][x] >= 0)
				dist3[y][x] = dist_player[y][x] * 0.3 + dist[y][x] * 0.7;
			else
				dist3[y][x] = 0;
		}
	}

	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < map_data_b[y].size(); x++) {
			if (dist4[y][x] >= 0)
				dist4[y][x] = dist_player[y][x] * 0.2 + dist[y][x] * 0.8;
			else
				dist4[y][x] = 0;
		}
	}

	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < map_data_b[y].size(); x++) {
			if (dist5[y][x] >= 0)
				dist5[y][x] = dist_player[y][x] * 0.4 + dist[y][x] * 0.6;
			else
				dist5[y][x] = 0;
		}
	}

	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < map_data_b[y].size(); x++) {
			if (dist6[y][x] >= 0)
				dist6[y][x] = dist_player[y][x] * 0.4 + dist[y][x] * 0.6;
			else
				dist6[y][x] = 0;
		}
	}

}



/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();


	SpriteBatch.Begin();

	//for (int y = 0; y < 18; y++) {
	//	/*for (int x = 0; x < 32; x++)*/ {
	//		if (map_data[y] == "0") {
	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < 32; x++) {
			if (map_data_b[y][x] == '#') {
				SpriteBatch.Draw(*bg, Vector3(x * 50, y * 50, 0), RectWH(0, 150, 50, 50),cl);
			}
			else if (map_data_b[y][x] == '$') {
				/*SpriteBatch.Draw(*isu, Vector3(x * 50, y * 50, 0), RectWH(0, 0, 50, 50));*/
				SpriteBatch.Draw(*bg, Vector3(x * 50, y * 50, 0), RectWH(100, 700, 50, 50),cl);
			}
			else {

				SpriteBatch.Draw(*bg, Vector3(x * 50, y * 50, 0), RectWH(0, 50, 50, 50),cl);
			}
		}
	}

	for (int x = 14; x < 16; x++) {
		for (int y = 5; y < 13; y++) {
			SpriteBatch.Draw(*ton, Vector3(x * 50, y * 50, -1), RectWH(0, 0, 50, 50),cl);
		}
	}

	for (int x = 11; x < 19; x++) {
		for (int y = 8; y < 10; y++) {
			SpriteBatch.Draw(*ton, Vector3(x * 50, y * 50, -1), RectWH(0, 0, 50, 50),cl);
		}
	}

	for (int x = 3; x < 8; x++) {
		for (int y = 4; y < 5; y++) {
			SpriteBatch.Draw(*ton, Vector3(x * 50, y * 50, -1), RectWH(0, 0, 50, 50), cl);
		}
	}

	for (int x = 5; x < 6; x++) {
		for (int y = 2; y < 7; y++) {
			SpriteBatch.Draw(*ton, Vector3(x * 50, y * 50, -1), RectWH(0, 0, 50, 50), cl);
		}
	}

	for (int x = 25; x < 29; x++) {
		for (int y = 6; y < 8; y++) {
			SpriteBatch.Draw(*ton, Vector3(x * 50, y * 50, -1), RectWH(0, 0, 50, 50), cl);
		}
	}


	for (int x = 24; x < 29; x++) {
		for (int y = 13; y < 14; y++) {
			SpriteBatch.Draw(*ton, Vector3(x * 50, y * 50, -1), RectWH(0, 0, 50, 50), cl);
		}
	}

	for (int x = 26; x < 27; x++) {
		for (int y = 11; y < 16; y++) {
			SpriteBatch.Draw(*ton, Vector3(x * 50, y * 50, -1), RectWH(0, 0, 50, 50), cl);
		}
	}

	for (int x = 6; x < 8; x++) {
		for (int y = 14; y < 16; y++) {
			SpriteBatch.Draw(*ton, Vector3(x * 50, y * 50, -1), RectWH(0, 0, 50, 50), cl);
		}
	}

	//SpriteBatch.Draw(*oni, oni_pos,oni_alpha);
	if (attack_state == 1)
	{
		SpriteBatch.Draw(*tracker_attack, Vector3(tracker_pos.x, tracker_pos.y - 20, 0), RectWH(50 * (int)tracker_flame_x, 70 * (int)direc4, 50, 70), tracker_alpha);
	}
	else if (tracker_state == 1)
	{
		SpriteBatch.Draw(*oniwin, Vector3(tracker_pos.x, tracker_pos.y - 20, 0), RectWH(50 * (int)win_flame, 0, 50, 70), tracker_alpha);
	}
	else if (tracker_state == 2)
	{
		SpriteBatch.Draw(*lose, Vector3(tracker_pos.x, tracker_pos.y - 20, 0), RectWH(50 * (int)lose_flame, 0, 50, 70), invisible_alpha);
	}
	else
	{
		SpriteBatch.Draw(*tracker, Vector3(tracker_pos.x, tracker_pos.y - 20, 0), RectWH((int)anime * 50, (int)direc4 * 70, 50, 70), tracker_alpha);
	}


	//SpriteBatch.Draw(*onipunch, Vector3(0, 0, 0), RectWH(50 * (int)oni_flame_x, 70 * (int)oni_flame_y, 50, 70), oni_alpha);
	if (tracker_state == 1) {
		SpriteBatch.Draw(*down, Vector3(player_pos.x, player_pos.y - 20, 0), RectWH(50 * (int)down_flame, (int)direc * 70, 50, 70), invisible_alpha);
	}
	else if (tracker_state == 2) {
		SpriteBatch.Draw(*playerwin, Vector3(player_pos.x, player_pos.y - 20, 0), RectWH(50 * (int)win_flame, 0, 50, 70), invisible_alpha);
	}
	else
	{
		SpriteBatch.Draw(*player, Vector3(player_pos.x, player_pos.y - 20, 0), RectWH((int)anime * 50, (int)direc * 70, 50, 70), invisible_alpha);
	}

	SpriteBatch.Draw(*player, Vector3(fake_pos.x, fake_pos.y - 20, 0), RectWH((int)anime * 50, (int)direc2 * 70, 50, 70), invisible_alpha);
	SpriteBatch.Draw(*player, Vector3(fake2_pos.x, fake2_pos.y - 20, 0), RectWH((int)anime * 50, (int)direc3 * 70, 50, 70), invisible_alpha);

	
	SpriteBatch.Draw(*player, Vector3(fake3_pos.x, fake3_pos.y - 20, 0), RectWH((int)anime * 50, (int)direc5 * 70, 50, 70), a_alpha);
		
	SpriteBatch.Draw(*player, Vector3(fake4_pos.x, fake4_pos.y - 20, 0), RectWH((int)anime * 50, (int)direc6 * 70, 50, 70), a_alpha);
		
	

	SpriteBatch.Draw(*player, Vector3(fake5_pos.x, fake5_pos.y - 20, 0), RectWH((int)anime * 50, (int)direc7 * 70, 50, 70), b_alpha);
	SpriteBatch.Draw(*player, Vector3(fake6_pos.x, fake6_pos.y - 20, 0), RectWH((int)anime * 50, (int)direc8 * 70, 50, 70), b_alpha);
	/*if (p_walk_flag == 0)
	{
		SpriteBatch.Draw(*player, player_pos, invisible_alpha);
	}

	if (p_walk_flag == 1)
	{
		SpriteBatch.Draw(*playerwalk, player_pos, RectWH(50 * (int)p_flame_x, 210 * (int)p_flame_y, 50, 70), invisible_alpha);
	}
	if (p_walk_flag == 2)
	{
		SpriteBatch.Draw(*playerwalk, player_pos, RectWH(50 * (int)p_flame_x, 140 * (int)p_flame_y, 50, 70), invisible_alpha);
	}*/



	/*for (int y = 0; y < 18; y++) {
		for (int x = 0; x < dist[y].size(); x++) {
			SpriteBatch.DrawString(DefaultFont, Vector2(x * 48, y * 16), Color(0, 0, 0), _T("%01.3f"), dist3[y][x]);
		}
	}*/

	SpriteBatch.DrawString(newfont, Vector2(0, 0), Color(0, 0, 255), _T("スキル使えるまで:%03d"), (int)skil_time / 60);
	/*SpriteBatch.DrawString(newfont, Vector2(100, 0), Color(255, 0, 0), _T("%03d"), (int)randam_skil);*/
	//SpriteBatch.DrawString(DefaultFont, Vector2(0, 0), Color(0, 0, 0), _T("%03f"), player_pos.x);

	//SpriteBatch.DrawString(DefaultFont, Vector2(1000, 0), Color(0, 0, 0), _T("%03f"), dist[0]);
	/*for (int i = 0; i < dist.size(); i++) {
		switch (mm[i]) {
		case 1 :


	}*/

	SpriteBatch.DrawString(newfont, Vector2(960, 0),
		Color(0, 0, 255), _T("TIME:%d"), time);


	if (skill_state == true)
	{
		SpriteBatch.Draw(*skill, Vector3(0.0f, 0.0f, -10.0f), skill_alpha);
	}






	SpriteBatch.End();

	GraphicsDevice.EndScene();
}



