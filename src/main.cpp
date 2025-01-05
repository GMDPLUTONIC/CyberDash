#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelEditorLayer.hpp>
class $modify(MyLevelEditorLayer, LevelEditorLayer) {
	bool init() {
		if (!LevelEditorLayer::init()) {
			return false;
		}

		log::debug("Hello from my MenuLayer::init hook! This layer has {} children.", this->getChildrenCount());

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png"),
			this,
			menu_selector(MyLevelEditorLayer::onRampppant)
		);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(Rampppant);

		Rampppant->setID("Rampppant"_spr);

		menu->updateLayout();

		return true;
	}

	void onRampppant(CCObject*) {
		FLAlertLayer::create("Rampppant", "<cr>Welcome To Rampppant</c>. You Can Access The Lists In The Corner Of The Screen.", "OK")->show();
	}
};