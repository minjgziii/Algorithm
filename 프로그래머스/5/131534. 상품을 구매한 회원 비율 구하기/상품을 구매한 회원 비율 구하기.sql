SELECT YEAR(SALES_DATE) AS YEAR, MONTH(SALES_DATE) AS MONTH, COUNT(DISTINCT O.USER_ID) AS PUCHASED_USERS, ROUND(COUNT(DISTINCT O.USER_ID)/(SELECT COUNT(*) FROM USER_INFO WHERE JOINED LIKE "2021%"), 1) AS PUCHASEDD_RATIO
FROM USER_INFO AS U
JOIN ONLINE_SALE AS O
ON U.USER_ID = O.USER_ID
WHERE O.USER_ID IN
(SELECT USER_ID
FROM USER_INFO
WHERE JOINED LIKE "2021%")
GROUP BY YEAR(SALES_DATE), MONTH(SALES_DATE)
ORDER BY YEAR, MONTH