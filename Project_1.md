
# Table of Contents

1.  [Step 1](#orgddd7f7d)
2.  [Requirement 1](#orgbc4e501)
    1.  [Insertion HOTEL](#org6a06738)
    2.  [Insertion ROOM](#orgb0ef9b7)
    3.  [Insertion GUEST](#org7b734b1)
3.  [Insertion BOOKING](#org3ec530d)
4.  [Questions](#org14d639f)
    1.  [1. List the price and type for each room at the Venetian Hotel.](#orge4248f5)
    2.  [2. List the names and addresses of all guests in Macao, alphabetically ordered by name.](#org464fb1f)
    3.  [3. List all double or family rooms with a price below $170.00 per night at the hotels in Macao, in ascending order of price.](#org51a5cf1)
    4.  [4. How many different guests have made booking in March?](#orgd520c2c)
    5.  [5. What is the total revenue per night from all double rooms in Macao?](#org88fe6ee)
    6.  [6. List the rooms and prices that are unoccupied at the Venetian Hotel in March 14,2021.](#org8b3666d)
    7.  [7. List the total number of rooms for each hotel in Macao.](#org804733c)
    8.  [8. What is the average price of a room for the hotels in Macao?](#org210c389)
    9.  [9. What is the most commonly booked room type for each hotel in Macao?](#org72b87dd)
    10. [10. What is the total income from bookings for the hotels in Macao in March?](#org780a095)



<a id="orgddd7f7d"></a>

# Step 1

1.  Login in [ORACLE APEX](http:202.175.25.24:8081/apex)
2.  Workspace : [$class<sub>code</sub>+&rsquo;-&rsquo;+$year]
3.  User name : Student<sub>Number</sub>
4.  Password  : Password


<a id="orgbc4e501"></a>

# Requirement 1

1.  create tables
    
    <table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
    
    
    <colgroup>
    <col  class="org-left" />
    
    <col  class="org-left" />
    
    <col  class="org-left" />
    
    <col  class="org-left" />
    
    <col  class="org-left" />
    
    <col  class="org-left" />
    </colgroup>
    <thead>
    <tr>
    <th scope="col" class="org-left">Table Name</th>
    <th scope="col" class="org-left">Key1</th>
    <th scope="col" class="org-left">Key2</th>
    <th scope="col" class="org-left">Key3</th>
    <th scope="col" class="org-left">Key4</th>
    <th scope="col" class="org-left">Key5</th>
    </tr>
    </thead>
    
    <tbody>
    <tr>
    <td class="org-left">Hotel</td>
    <td class="org-left">hotelNo</td>
    <td class="org-left">hotelname</td>
    <td class="org-left">city</td>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">&#xa0;</td>
    </tr>
    
    
    <tr>
    <td class="org-left">Room</td>
    <td class="org-left">roomNo</td>
    <td class="org-left">hotelNo</td>
    <td class="org-left">type</td>
    <td class="org-left">price</td>
    <td class="org-left">&#xa0;</td>
    </tr>
    
    
    <tr>
    <td class="org-left">Booking</td>
    <td class="org-left">hotelNo</td>
    <td class="org-left">guestNo</td>
    <td class="org-left">dateFrom</td>
    <td class="org-left">dateTo date</td>
    <td class="org-left">room<sub>No</sub></td>
    </tr>
    
    
    <tr>
    <td class="org-left">Guest</td>
    <td class="org-left">guestNo</td>
    <td class="org-left">guestName</td>
    <td class="org-left">guestAddress</td>
    <td class="org-left">&#xa0;</td>
    <td class="org-left">&#xa0;</td>
    </tr>
    </tbody>
    </table>
2.  Observation variable property
    -   hotelNo : varchar2(4)
    -   hotelName : varchar2(4)
    -   city : varchar2(4)
    -   roomNo : number(4)
    -   type : type(char)
    -   price : number(3)
    -   guestNo : number(5)
    -   guestName : varchar2(4)
    -   guestAddress : varchar(15)
    -   dateFrom : date
    -   dateTo : date
    -   roomNo : number(4)
3.  Commands
    1.  Hotel
        
            CREATE TABLE Hotel(
               hotelNo varchar2(4) PRIMARY KEY,
               hotelName varchar2(15) NOT NULL,
               city varchar2(15) NOT NULL
            );
    2.  Room
        
            CREATE TABLE Room(
               roomNo number(4) NOT NULL,
               hotelNo varchar2(4) NOT NULL,
            
               type CHAR(1) CONSTRAINT ROOMS_TYPE_CK CHECK (type IN ('S','D','F')) NOT NULL,
               price number(3) CONSTRAINT ROOMS_PRICE_CK CHECK (price BETWEEN 10 AND 250) NOT NULL,
            
               CONSTRAINT HOTEL_FK FOREIGN KEY (hotelNo) REFERENCES Hotel(hotelNo),
               CONSTRAINT ROOM_PK PRIMARY KEY (roomNo,hotelNo)
            );
    3.  Guest
        
            CREATE TABLE Guest(
               guestNo number(5) PRIMARY KEY,
               guestName varchar2(15) NOT NULL,
               guestAddress varchar2(15) NOT NULL
            );
    4.  Booking
        
            CREATE TABLE Booking(
               hotelNo varchar2(4) NOT NULL,
               guestNo number(5) NOT NULL,
               dateFrom date NOT NULL,
               dateTo date NOT NULL,
               roomNo number(4) NOT NULL,
               CONSTRAINT DATE_TO_CK CHECK (dateTo > dateFrom),
               CONSTRAINT BOOKING_ROOM_FK FOREIGN KEY (hotelNo,roomNo) REFERENCES Room (hotelNo,roomNo),
               CONSTRAINT BOOKING_HOTEL_FK FOREIGN KEY (hotelNo) REFERENCES HOTEL(hotelNo),
               CONSTRAINT BOOKING_GUEST_FK FOREIGN KEY (guestNo) REFERENCES Guest (guestNo),
               CONSTRAINT BOOKING_PK PRIMARY KEY (hotelNo, guestNo, dateFrom, roomNo)
            )


<a id="org6a06738"></a>

## Insertion HOTEL

    insert into HOTEL values ('mc01','Venetian','Macao');
    insert into HOTEL values ('hk01','Holiday','Hongkong');
    insert into HOTEL values ('mc02','Sands','Macao');
    insert into HOTEL values ('mc03','Lisboa','Macao');


<a id="orgb0ef9b7"></a>

## Insertion ROOM

    insert into ROOM values (1001,'mc01','S',120);
    insert into ROOM values (2001,'mc01','D',150);
    insert into ROOM values (2002,'mc01','D',170);
    insert into ROOM values (3001,'mc01','F',180);
    insert into ROOM values (3002,'mc01','F',200);
    insert into ROOM values (1001,'hk01','S',100);
    insert into ROOM values (2001,'hk01','D',120);
    insert into ROOM values (3001,'hk01','F',150);
    insert into ROOM values (1001,'mc02','S',130);
    insert into ROOM values (2001,'mc02','D',160);
    insert into ROOM values (3001,'mc02','F',180);
    insert into ROOM values (1011,'mc03','S',80);
    insert into ROOM values (9001,'mc03','D',90);
    insert into ROOM values (8002,'mc03','F',120);


<a id="org7b734b1"></a>

## Insertion GUEST

    insert into GUEST values (10001,'Marcus','London');
    insert into GUEST values (10002,'Philip','London');
    insert into GUEST values (10003,'Mark','Macao');
    insert into GUEST values (10004,'John','Macao');
    insert into GUEST values (10005,'Peter','Hongkong');
    insert into GUEST values (10006,'Bob','Beijing');
    insert into GUEST values (10007,'Alex','Shanghai');
    insert into GUEST values (10008,'Cindy','Beijing');
    insert into GUEST values (10009,'Wendy','Shenzhen');
    insert into GUEST values (10010,'Bill','Macao');
    insert into GUEST values (10011,'Billy','Hongkong');


<a id="org3ec530d"></a>

# Insertion BOOKING

    insert into BOOKING values ('mc01',10002,'01/12/2021','03/12/2021',1001);
    insert into BOOKING values ('mc01',10003,'03/11/2021','03/15/2021',2001);
    insert into BOOKING values ('mc01',10005,'01/20/2021','03/15/2021',3001);
    insert into BOOKING values ('mc01',10001,'03/15/2021','03/16/2021',2002);
    insert into BOOKING values ('mc02',10005,'02/18/2021','02/20/2021',2001);
    insert into BOOKING values ('hk01',10001,'03/13/2021','03/15/2021',2001);
    insert into BOOKING values ('mc03',10007,'02/12/2021','02/14/2021',1011);
    insert into BOOKING values ('mc03',10008,'03/01/2021','03/10/2021',9001);
    insert into BOOKING values ('hk01',10009,'04/10/2021','04/14/2021',3001);
    insert into BOOKING values ('mc02',10010,'04/01/2021','04/04/2021',3001);
    insert into BOOKING values ('mc02',10011,'02/21/2021','02/24/2021',1001);


<a id="org14d639f"></a>

# Questions


<a id="orge4248f5"></a>

## 1. List the price and type for each room at the Venetian Hotel.

    SELECT price,type FROM ROOM
    WHERE hotelNo = (SELECT hotelNo FROM HOTEL
                     WHERE hotelName = 'Venetian');

[Picture](Project_1_data/q_1.png)


<a id="org464fb1f"></a>

## 2. List the names and addresses of all guests in Macao, alphabetically ordered by name.

    SELECT h.guestName, h.guestAddress FROM Guest h
    WHERE h.guestAddress = 'Macao'
    ORDER BY h.guestName;

[Picture](Project_1_data/q_2.png)


<a id="org51a5cf1"></a>

## 3. List all double or family rooms with a price below $170.00 per night at the hotels in Macao, in ascending order of price.

    SELECT * FROM ROOM
    WHERE hotelNo IN (SELECT hotelNo FROM HOTEL
    WHERE City = 'Macao')
    AND type IN ('D','F')
    AND price < 170
    ORDER BY price DESC;

[Picture](Project_1_data/q_3.png)


<a id="orgd520c2c"></a>

## 4. How many different guests have made booking in March?

    SELECT count(DISTINCT guestNo) count FROM BOOKING
    WHERE EXTRACT(MONTH FROM dateTo) >= 3;

[picture](Project_1_data/q_4.png)


<a id="org88fe6ee"></a>

## 5. What is the total revenue per night from all double rooms in Macao?

    SELECT * FROM ROOM
    WHERE hotelNo IN (SELECT hotelNo FROM HOTEL
    WHERE City = 'Macao')
    AND type = 'D';

[Picture](Project_1_data/q_5.png)


<a id="org8b3666d"></a>

## 6. List the rooms and prices that are unoccupied at the Venetian Hotel in March 14,2021.

    with sqtable_1 as (
    select r.hotelNo, r.roomNo, r.price from
    Room r, Hotel h
    Where r.hotelNo = h.hotelNo
    AND h.hotelName = 'Venetian'
    )
    (
    select sq.roomNo, sq.price
    from sqtable_1 sq
    Where sq.roomNo not in (
        select roomNo
        from Booking
        where hotelNo = (
            select hotelNo
            from Hotel
            where hotelName = Venetian')
        )
        AND to_date(dateFrom) < to_date('3/14/2021')
        AND to_date(dateTo) > to_date('3/14/2021')
    )

[Picture](Project_1_data/q_6.png)


<a id="org804733c"></a>

## 7. List the total number of rooms for each hotel in Macao.

    select h.hotelno,h.hotelname,count(h.hotelno) idle_room
    from room r,hotel h
    where r.hotelno = h.hotelno
    and r.hotelno in (select hotelno from hotel
    where city = 'Macao')
    group by h.hotelno,h.hotelname;

[Picture](Project_1_data/q_7.png)


<a id="org210c389"></a>

## 8. What is the average price of a room for the hotels in Macao?

    SELECT avg(r.price) Average
    FROM Room r,Hotel h
    where r.hotelNo = h.hotelNo
    and r.hotelNo in (select hotelNo from Hotel
    where city = 'Macao')

[Picture](Project_1_data/q_8.png)


<a id="org72b87dd"></a>

## 9. What is the most commonly booked room type for each hotel in Macao?

    with sqtable_1 as (
        select b.hotelno, r.type, count(r.type) times
        from room r, booking b
        where r.hotelno = b.hotelno
        and r.hotelno in (
            select hotelno
            from hotel
            where city = 'Macao'
            )
        and r.roomno = b.roomno
        group by b.hotelno, r.type
        order by count(r.type) desc)
    (
    select * from sqtable_1 sq1, hotel sqh
    where sq1.hotelno = sqh.hotelno
    and sq1.times=(
    select max(sq2.times)
    from sqtable_1 sq2
    where sq1.hotelno = sq2.hotelno)
    )


<a id="org780a095"></a>

## 10. What is the total income from bookings for the hotels in Macao in March?

    select
    sum(
        (
        case
        when (extract(month from b.dateFrom))<3 and (extract(month from b.dateTo))=3
        then b.dateTo-to_date('03/1/2021')
        when (extract(month from b.dateFrom))=3 and (extract(month from b.dateTo))>3
        then 30
        when (extract(month from b.dateFrom))<3 and (extract(month from b.dateTo))>3
        then to_date('03/1/2021')-b.dateFrom
        else b.dateTo-b.dateFrom
        end + 1
    )*r.price) Profit_At_March_In_Macao
    from Booking b,Room r where b.hotelNo in (
        select hotelNo from Hotel
        where city = 'Macao')
    AND (b.hotelNo = r.hotelNo AND b.roomNo = r.roomNo)
    AND(
          (EXTRACT(MONTH FROM b.dateFrom) <= 3) and (EXTRACT(MONTH FROM b.dateTo) >= 3)
       )

