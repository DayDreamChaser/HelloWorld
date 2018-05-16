/* 謹嶷燕 */
/* 鴻吶燕Generalized List */ 
/*    ！！！！！！！！！！ */ 
/*   |     |  Data |     | */
/*   | TAG | ！！！| Next| */
/*   |     |SubLIst|     | */
/*    ！！！！！！！！！！ */ 
 typedef int ElementType;
 typedef struct GNode *GList;
 struct GNode(
 	int Tag;
 	union {
	 	ElementType Data;
	 	GList SubList;
    }URregion;
 	GList Next;
 );