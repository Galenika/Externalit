
#include "sdk\sdk.h"
using namespace sdk;
using namespace sdk::offys;
auto encrypt(std::string mess) -> std::string {
	return mess;
}
auto decrypt(std::string mess) -> std::string {
	return mess;
}
auto visuals_theard() -> void {
	do {
		if (settings_t.visuals.chams) features::visuals::c_glow->think();
		if (settings_t.visuals.glow_esp) features::visuals::c_chams->think();
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	} while (true);
}
auto misc_theard() -> void {
	do {
		if (settings_t.misc.auto_pistol) features::misc::c_autopistol->think();
		if (settings_t.misc.bunny_hop) features::misc::c_bunnyhop->think();
		if (settings_t.misc.clan_tag) features::misc::c_clantag->think();
		if (settings_t.misc.fake_lag) features::misc::c_fakelag->think();
		if (settings_t.misc.fov_changer)features::misc::c_fovchanger->think();
		if (settings_t.misc.no_flash)features::misc::c_noflash->think();
		if (settings_t.misc.radar_hack)features::misc::c_radarhack->think();
		if (settings_t.misc.rank_reveal) features::misc::c_rankreveal->think();
		if (settings_t.misc.slow_aim)features::misc::c_slowaim->think();
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	} while (true);
}
auto aimbot_theard() -> void {
	do {
		globals::local = csgo::c_client->get_local();
		globals::weapon = globals::local->get_weapon();
		if (settings_t.aimbot) features::aimbot::c_aimbot->think();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	} while (true);
}
auto triggerbot_theard() -> void {
	do {
		if (settings_t.triggerbot) features::triggerbot::c_triggerbot->think();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	} while (true);
}
auto skinchanger_theard() -> void {
	do {
		if (GetAsyncKeyState(2))
			csgo::c_engine->full_update();
		if (settings_t.skinchanger) features::skinchanger::c_skinchanger->think();
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	} while (true);
}
auto main() -> uint32_t
{
	c_memory->get_processid("csgo.exe");
	c_memory->attach("csgo.exe");
	offys::clientdll = c_memory->get_module("client_panorama.dll");
	offys::enginedll = c_memory->get_module("engine.dll");
	std::thread visuals_t(visuals_theard);
	std::thread misc_t(misc_theard);
	std::thread aimbot_t(aimbot_theard);
	std::thread triggerbot_t(triggerbot_theard);
	std::thread skinchanger_t(skinchanger_theard);

	aimbot_t.join();
	visuals_t.join();
	misc_t.join();
	triggerbot_t.join();
	skinchanger_t.join();	

    return 0;
}

