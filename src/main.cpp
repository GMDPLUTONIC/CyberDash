#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>

class $modify(MenuLayer){
    bool init() {
        if (!MenuLayer::init()) return false;

        if (!Mod::get()->setSavedValue("seen-intro-popup", true)) {
            FLAlertLayer* popup = FLAlertLayer::create(
                "SpaceMenu",
                "Welcome to SpaceMenu!\n<cb>Use the Page Down key or press the button.</c>",
                "OK"
            );
            popup->m_scene = this;
            popup->show();
        }
	}
}

class $modify(MyMenuLayer, MenuLayer) {

	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		log::debug("Hello from my MenuLayer::init hook! This layer has {} children.", this->getChildrenCount());

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("main_btn.png"),
			this,
			/**
			 * Here we use the name we set earlier for our modify class.
			*/
			menu_selector(MyMenuLayer::onMyButton)
		);

		/**
		 * Here we access the `bottom-menu` node by its ID, and add our button to it.
		 * Node IDs are a Geode feature, see this page for more info about it:
		 * https://docs.geode-sdk.org/tutorials/nodetree
		*/
		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(myButton);

		/**
		 * The `_spr` string literal operator just prefixes the string with
		 * your mod id followed by a slash. This is good practice for setting your own node ids.
		*/
		myButton->setID("my-button"_spr);

		/**
		 * We update the layout of the menu to ensure that our button is properly placed.
		 * This is yet another Geode feature, see this page for more info about it:
		 * https://docs.geode-sdk.org/tutorials/layouts
		*/
		menu->updateLayout();

		/**
		 * We return `true` to indicate that the class was properly initialized.
		 */
		return true;
	}

	/**
	 * This is the callback function for the button we created earlier.
	 * The signature for button callbacks must always be the same,
	 * return type `void` and taking a `CCObject*`.
	*/
	void onMyButton(CCObject*) {
		FLAlertLayer::create("Rampppant", "<cr>Welcome To Rampppant!</c>You Can Open Rampppant", "OK")->show();
	}
};