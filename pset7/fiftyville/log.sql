-- Keep a log of any SQL queries you execute as you solve the mystery.

--Look at crime scene report
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";

--Look at total amount of Interviews at crime date
SELECT name FROM interviews WHERE month = 7 AND day = 28;

--Check the interview logs
SELECT transcript FROM interviews WHERE name = "Eugene";

--Check licence Plate of exiting cars
SELECT activity, license_plate, minute FROM courthouse_security_logs WHERE hour = 10 AND day = 28 AND month = 7;

-- Check ATM transactions
SELECT transaction_type, amount, account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location ="Fifer Street";

--Ckeck Airport Dates
Select id, abbreviation, full_name FROM airports WHERE city = "Fiftyville";

--Check flight details
SELECT hour, minute, destination_airport_id FROM flights WHERE origin_airport_id = 8 AND day = 29 AND month = 7 ORDER BY hour;

--Check destination airport
SELECT full_name, city FROM airports WHERE id = 4;

--Setup suspect list
SELECT name, phone_number, passport_number FROM people WHERE license_plate = "322W7JE" OR license_plate = "0NTHK55" OR license_plate = "1106N58";

--Check flight id
SELECT id FROM flights WHERE origin_airport_id = 8 AND destination_airport_id = 4 AND hour = 8 AND minute = 20 AND day = 29 AND month = 7;

--Cgeck id of final suspects
SELECT id FROM people WHERE name = "Madison" AND passport_number = 1988161715;

--Check bank account numbers
select account_number FROM bank_accounts WHERE person_id = 560886;

--Check phone call withh accomplice
SELECT receiver, duration FROM phone_calls WHERE caller = "(286) 555-6063" AND day = 28 AND month = 7;

--Check last two accomplice suspects
SELECT name, passport_number FROM people WHERE phone_number = "(310) 555-8568" OR phone_number = "(676) 555-6554";

--Duration of phone call gives final hint for accomplice
SELECT receiver, duration FROM phone_calls WHERE caller = "(286) 555-6063" AND day = 28 AND month = 7;