WITH TARGET_CAR AS (
    SELECT CAR_ID, COUNT(CAR_ID) AS RENT_COUNT FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE START_DATE >= '2022-08-01'
        AND START_DATE <= '2022-10-31'
            GROUP BY CAR_ID
)

SELECT MONTH(CR.START_DATE) AS `MONTH`,
        CR.CAR_ID, 
        COUNT(*) AS RECORDS 
            FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY CR
                    INNER JOIN TARGET_CAR TC
                    ON CR.CAR_ID = TC.CAR_ID
                        WHERE TC.RENT_COUNT >= 5
                        AND CR.START_DATE >= '2022-08-01'
                        AND CR.START_DATE <= '2022-10-31'
                            GROUP BY MONTH(CR.START_DATE), CR.CAR_ID
                                ORDER BY MONTH(CR.START_DATE), CR.CAR_ID DESC
