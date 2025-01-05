#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>

class $modify(MyMenuLayer, MenuLayer) {

	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		log::debug("Hello from my MenuLayer::init hook! This layer has {} children.", this->getChildrenCount());

		auto myButton = CCMenuItemSpriteExtra::create(
		auto spr = CircleButtonSprite::createWithSpriteFrameName("top-sprite.png"_spr);
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
		FLAlertLayer::create("Encouraging Dash", "<cr>Never Give Up. You Will Succeed.</c>", "Close")->show();
	}

//	int randomInt(int min, int max) {
//		static std::random_device device;
//	    static std::mt19937 generator(device());
//	    std::uniform_int_distribution<int> distribution(min, max);
//
//      return distribution(generator);
//}


//	int main()
//	{
//	   std::vector<int> nums {1,2,3,4,5,6,7,8,9};
//
//	    std::cout << nums[randomInt(0, nums.size() - 1)];
//
//	},

};