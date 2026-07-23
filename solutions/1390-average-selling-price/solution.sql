# Write your MySQL query statement below
SELECT p.product_id, ROUND(IFNULL(SUM(p.price*u.units)/SUM(u.units),0),2)AS average_price
FROM UnitsSold u
RIGHT JOIN Prices p ON u.product_id=p.product_id AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY product_id; 

