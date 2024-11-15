# Write your MySQL query statement below
SELECT SUBSTR(Convert(trans_date, char), 1, 7) as month,
country,
COUNT(id) as trans_count,
SUM(state = 'approved') as approved_count,
SUM(amount) as trans_total_amount,
SUM(case when state = 'approved' then amount else 0 end) as approved_total_amount
from Transactions 
group by month, country;