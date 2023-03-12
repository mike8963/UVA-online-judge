解法:

1. 10030的題目範例跟題目要求的輸入格式不一樣，需要多花點時間看格式需求。

2. 題目要求server有全部的資料完整名稱，所以先建立一個array儲存所有的資料完整名稱。

3. 題目說明server會分別給兩個client資料名稱中的名稱&extension(ex. filename.txt會被分成filename跟txt)
題目中沒有說會給哪個client哪個部份的data，但發出詢問一律是從拿到extension的client開始提出，
所以就假設client A只會拿到name part，client B只會拿到extension part，分別用兩個array去儲存。
(後續覺得用三個array名稱會有點亂，所以改用struct)


4. 用一個map儲存各個name part的出現次數，extension part 也同理，方便後面的candidate判斷。

5. 預設每個filename為candidate

6.主要結構部分: 

用for跑題目要求的溝通次數:

    用for去遍歷每個 file:
	
	如果file為candidate:
	    
	    如果此file的extension / name 出現次數為1:
	    (從extension開始，依序name -> extension -> name，持續到題目要求的溝通次數為止)	    
	    (如果次數為1，代表它可以被確定完整名稱，故它不是candidate，需要去除)	    
	
		file.candidate = 0
		
		如果此file的name/extension part出現次數 > 1:
		
		    將此file的name/extension part次數 -1(往後不需要再去判斷此file是否為candidate)


時間複雜度應該不高，所以沒有特地去優化，主要是處理結構的方面
以及查表時用了map(也可以自己建tree，但懶) 應該也有降低一點時間複雜度。