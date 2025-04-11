-- 코드를 작성해주세요
SELECT d1.ID, COUNT(d2.PARENT_ID) CHILD_COUNT FROM ECOLI_DATA d1 LEFT JOIN ECOLI_DATA d2
                        ON d1.ID = d2.PARENT_ID
        GROUP BY d1.ID
            ORDER BY d1.ID;