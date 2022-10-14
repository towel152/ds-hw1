*使用環境: Dev-c++ 5.11*

## Q1設計一種結構(struct)用來表示以下幾何圖形：矩形、三角形、圓形。

程式輸出：(範例)
    
    Name: rectangle 
    Length:10.00 
    Width:20.00 
    
    Name: triangle 
    Base:102.00 
    Height:450.00 
    
    Name: circle 
    Radius:2.50 

程式說明:

(8~27行)
* step1:定義三種幾何圖形的結構
  * 結構內包含:幾何圖形名稱、並使用union定義三種幾何圖形所需要的內容以節省空間

(31~48行)
* step2:撰寫主程式，並輸入三種幾何圖形所需之條件

(50~68行)
* step3:撰寫輸出副程式，輸出三種幾何圖形  

## Q2寫兩個函數式：readPoly 和 printPoly，讓使用者可以建立並列印多項式。

程式輸出：(範例) 

    Enter the number of terms in your polynomial (1<=n<=10): 3 
    Exponent: 3 
    Coefficient: 3 Exponent: 
    2 
    Coefficient: 2 Exponent: 
    1 
    Coefficient: 1 
    >>>3.00x^3 + 2.00x^2 + 1.00x^1 

程式說明:

*有改動readPoly、printfPoly之參數數量*

(8~13行)
* step1:定義多項式的結構，並宣告`polynomial terms[]`、`int avail`為全域變數

(132~144行)
* step2:撰寫主程式，輸入所需條件

* step3:撰寫副程式`readPoly`、`printfPoly`

   (110~130行)
   
  `readPoly`: 
  
  * step1: 輸入指定數目n個元素，`avail`表示索引值n+1，及最後一個元素的位置後的第一個空格
  
  (93~108行)
  * step2: 撰寫副程式`sort`，利用氣泡排序由大到小進行sort
  
  (59~90行)
  * step3: 撰寫副程式`padd`，將排列好的多項式進行同expon相加，並從avail開始進行重新儲存(沒有同expon也會重新存入到avail，以方便輸出)  
  
      `padd`:
      
      * step1:從頭開始掃過多項式，並計算是否有出現同expon
      * step2:若有相同，計算相同的數量為奇或偶，以決定相加次數，並將index運算跳過以計算數目，避免重複運算，最後呼叫`attach`從avail開始將新多項式加入
      * step3:若無相同，一樣呼叫`attach`從avail開始將多項式加入(方便輸出)
        
       (39~46行)  
       `attach`: 從avail(最尾端)開始將新多項式加入    

   (15~36行)     
   `printfPoly`:

   * step1:計算總共有幾個+號
   * step2:輸出
     
## Q3請寫一個 C 語言的程式
令 a 與 b 為下三角矩陣與上三角矩陣，d 為(n*n)個正整數的矩陣，使用者輸入數字 n 將亂數產生 n*n 個不重覆正整數加入 d 矩陣中，寫出一演算法來從 d 陣列中取出為 a 的下三角矩陣及取出為 b 的上三角矩陣。請印出 d 陣列、a 陣列及 b 陣列。

程式輸出：(範例) 

    輸入 n 值:3 
    d 陣列為: 
    7 4 5 
    1 6 3 
    9 2 8 
    
    a 陣列為: 
    7 0 0 
    1 6 0
    9 2 8 
    
    b 陣列為: 
    7 4 5 
    0 6 3 
    0 0 0   
    
程式說明:  
*無撰寫副程式，只需直直往下看即可*  

(7~11行)
* step1:定義矩陣結構  

(14~33行)  
* step2:獲取需要的變數及矩陣，並利用交換法產生不重複正整數  

(36~57行)  
* step3:建立並輸出n*n的矩陣  

(59~94行)  
* step4:取出下三角，只擷取row>=col的數值存入a矩陣，最後進行輸出(從[0][0]開始跑，若沒有a矩陣裡沒有紀錄就輸出0)  

(96~131行)  
* step5:取出上三角，只擷取row<=col的數值存入b矩陣，最後進行輸出(從[0][0]開始跑，若沒有b矩陣裡沒有紀錄就輸出0) 

