#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(HookSearch, LevelSearchLayer) {
	bool init(int in) {
		if (!LevelSearchLayer::init(in)) {
			return false;
		}
		CCNode* Filter;
		Filter = this->getChildByID("other-filter-menu");
		if (!Filter) {
			 if (!Loader::get()->isModLoaded("geode.node-ids")) {
				 Filter = this->getChildByType<CCMenu>(0);
				if (!Filter) {
					return true;
				}
				// bug fix
				if (!Filter->getLayout()) {
					auto winSize = CCDirector::get()->getWinSize();
					Filter->setLayout(
						ColumnLayout::create()
							->setAxisReverse(true)
							->setGap(10)
							->setAxisAlignment(AxisAlignment::End)
					);
					Filter->setAnchorPoint({1, 0.5f});
					Filter->setPosition({winSize.width - 5, Filter->getPositionY()});
					Filter->setContentSize({Filter->getContentSize().width, winSize.height-10});
				}
			 } else {return true;}
		}
		auto BRL_Button = CCMenuItemSpriteExtra::create(
			 CircleButtonSprite::createWithSprite(
                "main_btn.png"_spr,
                1.1,
               (Mod::get()->getSettingValue<bool>("dark-mode")) ? CircleBaseColor::DarkPurple : CircleBaseColor::Green,
                CircleBaseSize::Small
            ),
			this,
			menu_selector(HookSearch::pushbtncustom)
		);
