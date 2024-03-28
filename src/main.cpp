#include "main.hpp"

static modloader::ModInfo modInfo{MOD_ID, VERSION, 0};

Configuration &getConfig() {
  static Configuration config(modInfo);
  return config;
}

MOD_EXPORT void setup(CModInfo *info) noexcept {
  *info = modInfo.to_c();

  getConfig().Load();

  Paper::Logger::RegisterFileContextId(PaperLogger.tag);

  PaperLogger.info("Completed setup!");
}

MOD_EXPORT void late_load() noexcept {
  il2cpp_functions::Init();

  PaperLogger.info("Installing hooks...");

  PaperLogger.info("Installed all hooks!");
}