//
// Created by jasonkay on 2024/3/6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Widget.h" resolved

#include "widget.h"
#include "ui_Widget.h"
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);



  /// 点击选取文件按钮，弹出文件对话框
  connect(ui->pushButton, &QPushButton::clicked, [=]() {
    QString path = QFileDialog::getOpenFileName(this, "打开文件", ".");
    //将路径放入到lineEdit中
    ui->lineEdit->setText(path);

    /// 编码格式类
    /// QT 5:
//    QTextCodec * codec = QTextCodec::codecForName("gbk");
    /// QT 6:
//    ts.setEncoding(bUtf8 ? QStringConverter::Utf8 : QStringConverter::Latin1);

    /// 读取内容 放入到 textEdit中
    // QFile默认支持的格式是 utf-8
    QFile file(path); // 参数就是读取文件的路径
    // 设置打开方式
    file.open(QIODevice::ReadOnly);

    //QByteArray array = file.readAll();
    QByteArray array;
    while (!file.atEnd()) {
      array += file.readLine(); // 按行读
    }

    /// 将读取到的数据 放入textEdit中
    ui->textEdit->setText(array);
//    ui->textEdit->setText( codec->toUnicode(array)  );

    /// 对文件对象进行关闭
    file.close();

    /// 进行写文件
//    file.open(QIODevice::Append); //用追加方式进行写
//    file.write("啊啊啊啊啊");
//    file.close();

    /// QFileInfo 文件信息类
    QFileInfo info(path);

    qDebug() << "大小：" << info.size() << " 后缀名：" << info.suffix() << " 文件名称：" << info.fileName() << " 文件路径："
             << info.filePath();
    qDebug() << "创建日期：" << info.birthTime().toString("yyyy/MM/dd hh:mm:ss");
    qDebug() << "最后修改日期：" << info.lastModified().toString("yyyy-MM-dd hh:mm:ss");
  });
}

Widget::~Widget() {
  delete ui;
}
