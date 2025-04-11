-- 코드를 입력하세요
SELECT S1.user_id, S1.product_id FROM ONLINE_SALE S1 LEFT JOIN ONLINE_SALE S2 
            ON S1.user_id = S2.user_id 
            and S1.product_id = S2.product_id 
            and S1.sales_date <> S2.sales_date
                WHERE S2.user_id is not null
                    GROUP BY S1.user_id, S1.product_id
                        ORDER BY S1.user_id ASC, S1.product_id DESC;