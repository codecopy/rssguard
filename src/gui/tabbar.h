#ifndef TABBAR_H
#define TABBAR_H

#include "gui/iconthemefactory.h"

#include <QTabBar>
#include <QVariant>
#include <QToolButton>


class TabBar : public QTabBar {
    Q_OBJECT

  public:
    enum TabType {
      FeedReader    = 1000,
      NonClosable   = 1001,
      Closable      = 1002
    };

    // Constructors.
    explicit TabBar(QWidget *parent = 0);
    virtual ~TabBar();

    // Getter/setter for tab type.
    void setTabType(int index, const TabBar::TabType &type);

    inline TabBar::TabType tabType(int index) {
      return static_cast<TabBar::TabType>(tabData(index).value<int>());
    }

  protected slots:
    // Called when user selects to close tab via close button.
    void closeTabViaButton();

  protected:
    // Reimplementations.
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

  signals:
    // Emmited if empty space on tab bar is double clicked.
    void emptySpaceDoubleClicked();
};

#endif // TABBAR_H
