class ZenNotesClientConfig
{
	// Config location
	private const static string zenModFolder = "$profile:\\Zenarchist\\";
	private const static string zenConfigName = "ZenNotesClientConfig.json";

	// Main config data
	int LastUsedFontStyle;

	// Load config file
	void Load()
	{
		if (GetGame().IsClient())
		{
			if (FileExist(zenModFolder + zenConfigName))
			{	// If config exists, load file
				JsonFileLoader<ZenNotesClientConfig>.JsonLoadFile(zenModFolder + zenConfigName, this);
			}
		}
	}

	// Save config
	void Save()
	{
		if (!FileExist(zenModFolder))
		{	// If config folder doesn't exist, create it.
			MakeDirectory(zenModFolder);
		}

		// Save JSON config
		JsonFileLoader<ZenNotesClientConfig>.JsonSaveFile(zenModFolder + zenConfigName, this);
	}
}

// Save config data
ref ZenNotesClientConfig m_ZenNotesClientConfig;

// Helper function to return Config data storage object
static ZenNotesClientConfig GetZenNotesClientConfig()
{
	if (!m_ZenNotesClientConfig)
	{
		Print("[ZenNotesClientConfig] Init");
		m_ZenNotesClientConfig = new ZenNotesClientConfig;
		m_ZenNotesClientConfig.Load();
	}

	return m_ZenNotesClientConfig;
};