// This file is part of RSS Guard.
//
// Copyright (C) 2011-2017 by Martin Rotter <rotter.martinos@gmail.com>
//
// RSS Guard is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// RSS Guard is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RSS Guard. If not, see <http://www.gnu.org/licenses/>.

#ifndef SETTINGSBROWSERMAIL_H
#define SETTINGSBROWSERMAIL_H

#include "gui/settings/settingspanel.h"

#include "ui_settingsbrowsermail.h"


class SettingsBrowserMail : public SettingsPanel {
		Q_OBJECT

	public:
		explicit SettingsBrowserMail(Settings* settings, QWidget* parent = 0);
		virtual ~SettingsBrowserMail();

		inline QString title() const {
			return tr("Web browser & e-mail & proxy");
		}

		void loadSettings();
		void saveSettings();

	private slots:
    void addExternalTool();
    void deleteSelectedExternalTool();
		void changeDefaultBrowserArguments(int index);
		void selectBrowserExecutable();
		void changeDefaultEmailArguments(int index);
		void selectEmailExecutable();
		void displayProxyPassword(int state);
		void onProxyTypeChanged(int index);

	private:
    QStringList externalTools() const;
    void setExternalTools(const QStringList& list);

		Ui::SettingsBrowserMail* m_ui;
};

#endif // SETTINGSBROWSERMAIL_H
