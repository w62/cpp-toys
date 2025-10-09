#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QTimer>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  QTimer::singleShot(1000, &a, &QCoreApplication::quit);

  QTranslator translator;
  const QStringList uiLanguages = QLocale::system().uiLanguages();
  for (const QString &locale : uiLanguages) {
    const QString baseName = "untitled_" + QLocale(locale).name();
    if (translator.load(":/i18n/" + baseName)) {
      a.installTranslator(&translator);
      break;
    }
  }

  QTextStream inputStream(stdin);

  qInfo() << "Enter your username: ";
  QString username = inputStream.readLine();
  qInfo() << "Hello " << username;


  return a.exec();
}
