#ifndef INC_SETTINGS_H
#define INC_SETTINGS_H

#include "cmdline.h"

class Settings {

	public:

		enum Report {
			rtCSV, rtXML
		};

		Settings( CmdLine & cl );

		Report ReportType() const;
		std::string DictName() const;

	private:

		Report mRepType;
		std::string mDictName;
};

#endif
