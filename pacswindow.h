#ifndef PACSWINDOW_H
#define PACSWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDirIterator>
#include <QStringList>
#include <QLabel>
#include <QWidgetList>
#include <QStringList>
#include <QVector>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <QTimer>
#include <QVectorIterator>
#include <QStandardItemModel>
#include <QFile>
#include <QJsonObject>
#include <QSettings>
#include <QMimeDatabase>
#include <QMimeType>

#include "JlCompress.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PacsWindow; }
QT_END_NAMESPACE

class PacsWindow : public QMainWindow
{
    Q_OBJECT

public:
    PacsWindow(QWidget *parent = nullptr);
    ~PacsWindow();
    void Download_DICOM_orthanc();
    void initTables();


    QFileInfoList filelist;
    QDir dir,dir_upload,dir_download;
    int indexTable1;
    int numfiles = 0;
    int total_files =0;
    QJsonObject tagsdescription;
    QDataStream dataStream;
    QVector<QVector<QString>> tablepatientsInfo;
//    QVector<QVector<QString>> tablesstudiesInfo;



private:
    Ui::PacsWindow *ui;
    void UpdateListPatients(QString link);
    void UpdateListStudies(QString link);


    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkAccessManager *managerdownload = new QNetworkAccessManager(this);
    QNetworkAccessManager *managerpatient = new QNetworkAccessManager(this);
    QNetworkAccessManager *managerInit = new QNetworkAccessManager(this);
    QNetworkAccessManager *managerstudies= new QNetworkAccessManager(this);


public slots:

    void httpDownload(QNetworkReply *aux);
    void UpdateLoadPatients(QNetworkReply *aux);
    void receivePatientsList(QNetworkReply *aux);
    void receiveStudiesList(QNetworkReply *aux);
    void httpUpload(QNetworkReply *aux);

signals:
        void downloaded();
        void uploaded();
        void patientloaded();
        void initloaded();
        void studiesloaded();

private slots:
        void on_selectFolder_clicked();
        void on_nameListView_clicked(const QModelIndex &index);
        void on_studiesListView_clicked(const QModelIndex &index);
        void on_seriesListView_clicked(const QModelIndex &index);
        void on_pushButton_clicked();
};
#endif // PACSWINDOW_H
