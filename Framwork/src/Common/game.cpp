#include "game.h"

Game::Game(Engine* engine)
{
	m_engine = engine;

	//Display* window = engine->getWindow();

	SceneManager* sceneManager = engine->getSceneManager();
	ShaderManager* shaderManager = engine->getShaderManager();
	//AssetManager* assetManager = engine->getAssetManager();
	//GuiManager* guiManager = engine->getGuiManager();

	m_scene = sceneManager->addScene("test");

	m_camera = new Camera();
	m_scene->addCamera(m_camera);

    m_light = new Light();
    m_light->setType(Light::POINT);
    m_light->setPosition(glm::vec3(2.0f, 5.0f, 5.0f));
    m_light->setColor(glm::vec3(3.0f, 3.0f, 3.0f));
    m_light->setAttenuation(glm::vec3(1.0f, 0.05f, 0.005f));
    m_scene->addLight(m_light);

	//assetManager->importMesh("./res/models/plane.obj");
	//assetManager->importMesh("./res/models/torus.obj");
  
	Mesh* plane = m_scene->getMeshByName("Plane");
	//plane->getTransform()->setScale(glm::vec3(50.0f, 50.0f, 50.0f));
	//plane->getMaterial()->setTiling(glm::vec2(500.0f, 500.0f));
//	plane->getMaterial()->setBackFaceCulling(false);

	//Mesh* torus = m_scene->getMeshByName("TwistedTorus");

	//torus->getTransform()->setPosition(glm::vec3(0.0f, 0.25f, 0.0f));
	////lampb1->getMaterial()->setBackFaceCulling(false);

	//glm::vec4 white = glm::vec4(255.0f, 255.0f, 255.0f, 128.0f);
	//m_layout = guiManager->createLayout("main_window");

	//Menu* main_menu = new Menu(glm::vec2(0.0, 0.0), glm::vec2(1920, 30), "segoeui");

	//Menu::MenuItem* fileMenu = main_menu->addMenuItem("File");
	//fileMenu->addChild("New", &Game::newProject, "Ctrl + N", "PLUS_CIRCLED");
	//fileMenu->addChild("Open...", NULL, "Ctrl + O", "FOLDER_OPENED");
	//fileMenu->addSeparator();
	//fileMenu->addChild("Save", NULL, "Ctrl + S", "FLOPPY_DISK");
	//fileMenu->addChild("Save as...", NULL, "Ctrl + Shift + S", "FLOPPY_DISK");
	//fileMenu->addSeparator();
	//fileMenu->addChild("Import", NULL, "", "REPLY");
	//fileMenu->addChild("Export", NULL, "", "FORWARD");
	//fileMenu->addSeparator();
	//fileMenu->addChild("Quit", &Game::exitApplication, "Ctrl + Q", "EXIT");

	//Menu::MenuItem* editMenu = main_menu->addMenuItem("Edit");
	//editMenu->addChild("Undo", NULL, "Ctrl + Z");
	//editMenu->addSeparator();
	//editMenu->addChild("Cut", NULL, "Ctrl + X");
	//editMenu->addChild("Copy", NULL, "Ctrl + C");
	//editMenu->addChild("Paste", NULL, "Ctrl + V");

	//Menu::MenuItem* windowMenu = main_menu->addMenuItem("Window");
	//windowMenu->addChild("Fullscreen", &Game::setFullscreen, "F11", "RESIZE_FULL");

	//Menu::MenuItem* helpMenu = main_menu->addMenuItem("Help");
	//helpMenu->addChild("Documentation", NULL, "", "HELP_CIRCLED");

	//Layout* layout_tools = guiManager->createLayout("tools");
	//Layout* layout_outliner = guiManager->createLayout("outliner");

	//Window* toolsPanel = new Window("Tools", glm::vec2(0.0f, 29.0f), glm::vec2(200.0f, (1080.0f - 360.0f - 29.0f)), "segoeui");
	//toolsPanel->setOpacity(0.8f);
	//Window* outliner = new Window("Outliner", glm::vec2((1920.0f - 300.0f), 29.0f), glm::vec2(300.0f, (1080.0f - 29.0f)), "segoeui");
	//Table* outlinerTable = new Table(glm::vec2(1.0f, 65.0f), glm::vec2(299.0f, 299.0f), "segoeui");
	//outlinerTable->setName("outlinerTable");

	//std::vector<Mesh*> meshes = sceneManager->getCurrentScene()->getMeshes();
	//for (unsigned int i = 0; i < meshes.size(); i++)
	//{
	//	Table::Row* row = (Table::Row*)outlinerTable->addRow();
	//	row->addColumn(meshes[i]->getName());
	//	row->addColumn(std::to_string(meshes[i]->getVertexCount()));
	//	row->addColumn("lol");
	//}

	//outliner->addChild(outlinerTable);

	//Window* assets = new Window("Assets Manager", glm::vec2(0.0f, (1080.0f - 360.0f)), glm::vec2((1920.0f - 300.0f), 360.0f), "segoeui");
	//assets->setDrawingShadow(false);

	//toolsPanel->setState("draggable", true);
	//outliner->setState("draggable", true);


	//Image* image = new Image(guiManager->getContext(), "./res/textures/icon_big.png", glm::vec2(0.0f, 0.0f), glm::vec2(48.0f, 48.0f));

	//const std::string font = "segoeui";
	//m_fpsText = new Text("Fps:", white, glm::vec2(20.0f, 100.0f), font);
	//
	//m_profGame = new Text("Game:", white, glm::vec2(20, 120), font);
	//m_profInput = new Text("Input:", white, glm::vec2(20, 140), font);
	//m_profRender = new Text("Render:", white, glm::vec2(20, 160), font);
	//m_profSwapBuffer = new Text("SwapBuffer:", white, glm::vec2(20, 180), font);
	//m_profSleep = new Text("Sleep:", white, glm::vec2(20, 200), font);

	//m_labelName = new Label(glm::vec2(20, 20.0f), glm::vec2(210, 35), "Name", font);
	//m_inputName = new Input(glm::vec2(0, 30), glm::vec2(299, 35), font);
	//m_inputName->setPlaceholder("Search...");

	//outliner->addChild(m_inputName);

	//m_label = new Label(glm::vec2(20, 35.0f), glm::vec2(210, 35), "My super label", font);
	//m_input = new Input(glm::vec2(0, 30), glm::vec2(210, 35), font);
	//m_label->addChild(m_input);


	//m_button = new Button(glm::vec2(10.0f, 40.0f), glm::vec2(180, 30), font);
	//m_button->setText("Cube");

	//m_button->addEventListener("mouseUp", &Game::callbackFn);

	////toolsPanel->addChild(image);
	//toolsPanel->addChild(m_fpsText);
	//toolsPanel->addChild(m_profGame);
	//toolsPanel->addChild(m_profInput);
	//toolsPanel->addChild(m_profRender);
	//toolsPanel->addChild(m_profSwapBuffer);
	//toolsPanel->addChild(m_profSleep);

	////outliner->addChild(m_label);
	////outliner->addChild(m_labelName);
	//toolsPanel->addChild(m_button);


	//m_layout->addWidget(toolsPanel);
	//m_layout->addWidget(outliner);
	//m_layout->addWidget(assets);
	//m_layout->addWidget(main_menu);

	//m_angle = 0.0f;

	//json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
	//std::string s = j.dump();
	//std::cout << j.dump(4) << std::endl;
    
}




void Game::update(double delta)
{
	/*m_angle += (float)delta * 0.3f;

	if (m_fpsText != nullptr)
		m_fpsText->setText("Fps: " + std::to_string((int)round(m_engine->getFps())));

	if (m_profGame != nullptr)
		m_profGame->setText("Game: " + std::to_string(m_engine->getProfiler()->getReport("game")));

	if (m_profInput != nullptr)
		m_profInput->setText("Input: " + std::to_string(m_engine->getProfiler()->getReport("input")));

	if (m_profRender != nullptr)
		m_profRender->setText("Render: " + std::to_string(m_engine->getProfiler()->getReport("render")));

	if (m_profSwapBuffer != nullptr)
		m_profSwapBuffer->setText("SwapBuffer: " + std::to_string(m_engine->getProfiler()->getReport("swapBuffer")));

	if (m_profSleep != nullptr)
		m_profSleep->setText("Sleep: " + std::to_string(m_engine->getProfiler()->getReport("sleep")));*/
}

Game::~Game()
{

}
