SELECT B.ID, A.FISH_NAME, B.LENGTH FROM FISH_NAME_INFO A 
        INNER JOIN (SELECT ID, FISH_TYPE, LENGTH FROM FISH_INFO
                        WHERE (FISH_TYPE, LENGTH) in
                            (SELECT FISH_TYPE, MAX(LENGTH) AS LENGTH
                                FROM FISH_INFO
                                    GROUP BY FISH_TYPE)) B
        ON A.FISH_TYPE = B.FISH_TYPE
ORDER BY B.ID