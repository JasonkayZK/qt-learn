#include "dataconfig.h"
#include <QDebug>
#include <ctime>

dataConfig::dataConfig(QObject *parent) : QObject(parent) {
  srand(time(nullptr));

  //第一关
  int array1[4][4] = {{1, 0, 1, 1},
                      {0, 0, 1, 1},
                      {1, 1, 0, 0},
                      {1, 1, 0, 1}};
  //将数组插入容器中
  QVector<QVector<int>> v;
  for (auto &i : array1) {
    QVector<int> v1;
    for (int j = 0; j < 4; j++) {
      v1.push_back(i[j]);
    }
    v.push_back(v1);
  }
  //插入到配置文件中
  mData.insert(1, v);




  //第二关
  int array2[4][4] = {{0, 1, 0, 1},
                      {1, 0, 0, 0},
                      {1, 0, 0, 0},
                      {0, 1, 0, 1}};

  v.clear();
  for (auto &i : array2) {
    QVector<int> v1;
    for (int j = 0; j < 4; j++) {
      v1.push_back(i[j]);
    }
    v.push_back(v1);
  }

  mData.insert(2, v);

  int array3[4][4] = {{1, 0, 1, 1},
                      {1, 1, 0, 0},
                      {0, 0, 1, 1},
                      {1, 1, 0, 1}};
  v.clear();
  for (int i = 0; i < 4; i++) {
    QVector<int> v1;
    for (int j = 0; j < 4; j++) {
      v1.push_back(array3[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(3, v);

  int array4[4][4] = {{0, 1, 1, 1},
                      {1, 1, 0, 1},
                      {1, 0, 1, 1},
                      {1, 1, 1, 0}};
  v.clear();
  for (int i = 0; i < 4; i++) {
    QVector<int> v1;
    for (int j = 0; j < 4; j++) {
      v1.push_back(array4[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(4, v);

  int array5[4][4] = {{1, 0, 0, 1},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {1, 0, 0, 1}};
  v.clear();
  for (int i = 0; i < 4; i++) {
    QVector<int> v1;
    for (int j = 0; j < 4; j++) {
      v1.push_back(array5[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(5, v);

  int array6[4][4] = {{1, 0, 0, 1},
                      {0, 1, 1, 0},
                      {0, 1, 1, 0},
                      {1, 0, 0, 1}};
  v.clear();
  for (int i = 0; i < 4; i++) {
    QVector<int> v1;
    for (int j = 0; j < 4; j++) {
      v1.push_back(array6[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(6, v);

  int array7[4][4] = {{0, 1, 1, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 1, 1, 0}};
  v.clear();
  for (int i = 0; i < 4; i++) {
    QVector<int> v1;
    for (int j = 0; j < 4; j++) {
      v1.push_back(array7[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(7, v);

  int array8[4][4] = {{0, 1, 1, 0},
                      {1, 1, 1, 1},
                      {1, 1, 1, 1},
                      {0, 1, 1, 0}};
  v.clear();
  for (int i = 0; i < 4; i++) {
    QVector<int> v1;
    for (int j = 0; j < 4; j++) {
      v1.push_back(array8[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(8, v);

  int array9[4][4] = {{0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0}};
  v.clear();
  for (int i = 0; i < 4; i++) {
    QVector<int> v1;
    for (int j = 0; j < 4; j++) {
      v1.push_back(array9[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(9, v);
  //===============10随机关==================//
  v.clear();

  int num = 0;
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    QVector<int> v1;
    for (int j = 0; j < 4; j++) {
      num = rand() % 2;
      v1.push_back(num);
      if (num == 1) {
        sum++;
      }
    }
    v.push_back(v1);
  }

  //还需要设置成偶数个，奇数个不行，可以利用vector的性质来做
  int changedValue = *v.begin()->begin();//改变第一个

  if ((sum & 1) != 0) {
    //如果为奇数，则改变第一个
    if (changedValue == 0) {
      *v.begin()->begin() = 1;
    } else {
      *v.begin()->begin() = 0;
    }
  }
  mData.insert(10, v);

  //=================11-15 5个格子=======================


  int array11[5][5] = {{0, 0, 0, 0, 0},
                       {0, 1, 0, 1, 0},
                       {0, 0, 1, 0, 0},
                       {0, 1, 0, 1, 0},
                       {0, 0, 0, 0, 0}};
  v.clear();
  for (int i = 0; i < 5; i++) {
    QVector<int> v1;
    for (int j = 0; j < 5; j++) {
      v1.push_back(array11[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(11, v);

  int array12[5][5] = {{0, 0, 0, 1, 0},
                       {1, 0, 1, 1, 1},
                       {1, 0, 1, 1, 0},
                       {1, 0, 1, 1, 1},
                       {0, 0, 0, 1, 0}};
  v.clear();
  for (int i = 0; i < 5; i++) {
    QVector<int> v1;
    for (int j = 0; j < 5; j++) {
      v1.push_back(array12[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(12, v);

  int array13[5][5] = {{1, 1, 1, 0, 0},
                       {0, 1, 0, 0, 0},
                       {0, 1, 1, 1, 1},
                       {0, 1, 0, 0, 1},
                       {1, 1, 1, 0, 1}};
  v.clear();
  for (int i = 0; i < 5; i++) {
    QVector<int> v1;
    for (int j = 0; j < 5; j++) {
      v1.push_back(array13[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(13, v);

  int array14[5][5] = {{1, 1, 1, 1, 1},
                       {1, 0, 0, 0, 0},
                       {1, 0, 0, 0, 0},
                       {1, 0, 1, 1, 1},
                       {1, 0, 1, 1, 1}};
  v.clear();
  for (int i = 0; i < 5; i++) {
    QVector<int> v1;
    for (int j = 0; j < 5; j++) {
      v1.push_back(array14[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(14, v);


  //===============15随机关==================//
  v.clear();

  int num1 = 0;
  int sum1 = 0;
  for (int i = 0; i < 5; i++) {
    QVector<int> v1;
    for (int j = 0; j < 5; j++) {
      num1 = rand() % 2;
      v1.push_back(num1);
      if (num1 == 1) {
        sum1++;
      }
    }
    v.push_back(v1);
  }

  //还需要设置成偶数个，奇数个不行，可以利用vector的性质来做
  int changedValue1 = v[3][3];//改变中间那个

  if ((sum1 & 1) != 0) {
    //如果为奇数，则改变中间一个
    if (changedValue1 == 0) {
      v[3][3] = 1;
    } else {
      v[3][3] = 0;
    }
  }
  mData.insert(15, v);


  //================6*6===================//


//    int array16[6][6] = { {1, 1, 1, 1, 1, 1},
//                          {1, 1, 1, 1, 1, 1},
//                          {1, 1, 1, 0, 1, 1},
//                          {1, 1, 0, 0, 0, 1},
//                          {1, 1, 1, 0, 1, 1},
//                          {1, 1, 1, 1, 1, 1} };


  int array16[6][6] = {{0, 0, 0, 0, 0, 0},
                       {0, 1, 1, 1, 1, 0},
                       {0, 1, 1, 1, 1, 0},
                       {0, 1, 1, 1, 1, 0},
                       {0, 1, 1, 1, 1, 0},
                       {0, 0, 0, 0, 0, 0}};
  v.clear();
  for (auto &i : array16) {
    QVector<int> v1;
    for (int j = 0; j < 6; j++) {
      v1.push_back(i[j]);
    }
    v.push_back(v1);
  }

  mData.insert(16, v);

  int array17[6][6] = {{1, 1, 0, 0, 0, 0},
                       {1, 1, 0, 0, 0, 1},
                       {1, 1, 0, 0, 0, 0},
                       {1, 1, 0, 0, 0, 0},
                       {1, 1, 0, 0, 0, 1},
                       {1, 1, 0, 0, 0, 0}};
  v.clear();
  for (int i = 0; i < 6; i++) {
    QVector<int> v1;
    for (int j = 0; j < 6; j++) {
      v1.push_back(array17[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(17, v);

  int array18[6][6] = {{0, 0, 0, 0, 0, 1},
                       {0, 0, 1, 0, 0, 0},
                       {0, 1, 1, 0, 0, 0},
                       {1, 0, 0, 1, 1, 0},
                       {1, 1, 0, 1, 0, 0},
                       {1, 1, 1, 0, 0, 0}};
  v.clear();
  for (int i = 0; i < 6; i++) {
    QVector<int> v1;
    for (int j = 0; j < 6; j++) {
      v1.push_back(array18[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(18, v);

  int array19[6][6] = {{0, 0, 0, 0, 0, 0},
                       {1, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0}};
  v.clear();
  for (int i = 0; i < 6; i++) {
    QVector<int> v1;
    for (int j = 0; j < 6; j++) {
      v1.push_back(array19[i][j]);
    }
    v.push_back(v1);
  }

  mData.insert(19, v);

  //===============20随机关==================//
  v.clear();

  int num2 = 0;
  int sum2 = 0;
  for (int i = 0; i < 6; i++) {
    QVector<int> v1;
    for (int j = 0; j < 6; j++) {
      num2 = rand() % 2;
      v1.push_back(num2);
      if (num2 == 1) {
        sum2++;
      }
    }
    v.push_back(v1);
  }

  //还需要设置成偶数个，奇数个不行，可以利用vector的性质来做
  int changedValue2 = v[4][4];//改变中间那个

  if ((sum2 & 1) != 0) {
    //如果为奇数，则改变中间一个
    if (changedValue2 == 0) {
      v[4][4] = 1;
    } else {
      v[4][4] = 0;
    }
  }
  mData.insert(20, v);
  //===================额外测试关卡========================//

  //测试数据
  //    for( QMap<int, QVector< QVector<int> > >::iterator it = mData.begin();it != mData.end();it++ )
  //    {
  //         for(QVector< QVector<int> >::iterator it2 = (*it).begin(); it2!= (*it).end();it2++)
  //         {
  //            for(QVector<int>::iterator it3 = (*it2).begin(); it3 != (*it2).end(); it3++ )
  //            {
  //                qDebug() << *it3 ;
  //            }
  //         }
  //         qDebug() << endl;
  //    }

}
