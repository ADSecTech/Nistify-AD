#include "custom_headers.h"

#include "pch.h"

// Read the configuration from the registry
void readConfig(Config* conf)
{
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REGISTRY_SUBKEY };
    conf->api_server = key.GetStringValue(REGISTRY_SERVER_KEY);
    conf->resource_location = key.GetStringValue(REGISTRY_RESOURCE_KEY);
}