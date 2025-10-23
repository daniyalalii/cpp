# Question # 1

The university cafeteria has decided to modernize its traditional snack dispensers by
implementing an intelligent Smart Vending Machine System. This new system must not only
store and sell items but also maintain global statistics across multiple vending units operating
within the campus network.
Each vending machine in the system should represent a single physical unit installed in a different
location (e.g., cafeteria, library, or hostel). Every machine must have a unique machine ID that is
automatically generated when the object is created. The system should track the total number
of active machines through a static counter, which increases when a machine is created and
decreases when it is destroyed. This ensures that the network always knows how many machines
are currently operational.
Every vending machine will maintain a dynamic list of items, each containing the item name,
price, unique code, and available quantity. The machine should support adding new items,
restocking existing ones, and removing discontinued products. Items should be stored
dynamically using pointers and arrays. The addition and removal of items must be performed
using operator overloading:
• The += operator should allow adding a new item to the machine.
• The -= operator should allow removal of an item by its code or name.
The increment (++) and decrement (--) operators must also be overloaded. These should
simulate price adjustments — for example, the prefix version could increase all item prices by
5%, while the postfix version could decrease them by 5%, representing inflation and discount
cycles respectively. These overloaded operators should work seamlessly and update all item data
dynamically.
Each vending machine should have a copy constructor and an overloaded assignment operator
(=) that correctly handle copying machines. When a machine is copied, all its items must be
deeply copied to new memory, ensuring that modifying one machine does not affect the other.
The copy should have a new unique ID but maintain identical inventory details. Failure to perform
deep copies will cause shared memory corruption, creating a deliberate trap for shallow-copy
errors.
Customers can purchase items using their index in the vending list. To facilitate this, the subscript
operator ([]) should be overloaded so that machine[2] returns the second item. When an item is
purchased, its quantity must decrease by one, and if the stock reaches zero, it should
automatically be marked as "Out of Stock." Every purchase must update a static total sales
counter shared across all vending machines in the system.
Two vending machines can also be merged using the overloaded + operator. When two machines
merge, a new machine object should be created containing all unique items from both machines.If two machines contain the same item code, their stock quantities should be combined, and the
price should average out. This merged object will count as a new vending machine instance with
a new ID.
To provide system-wide reports, the implementation should include a friend function or friend
class (such as a ReportGenerator) that can directly access private members of all vending
machines. The friend should be able to display data such as total items sold, total revenue, and
number of active machines in the system.
Dynamic memory must be managed carefully. Each machine dynamically allocates memory for
its inventory; thus, destructors must properly free all resources when a machine is destroyed.
Forgetting to release memory should result in “ghost items” appearing in global reports — an
intentional design to test proper destructor logic.
A proper menu for each functionality is required.
---
# Question # 2
The software firm BlockVerse Technologies plans to create a simplified simulation of a Crypto
Wallet Network to demonstrate how cryptocurrency wallets, transactions, and mining
operations can be modeled using object-oriented programming concepts. The simulation will not
use inheritance or polymorphism. Instead, it will focus entirely on constructors, destructors,
copy constructors, static members, operator overloading, friend functions, dynamic memory
handling, arrays, pointers, and recursion.
Each wallet represents a unique user in the crypto system. Every wallet must have a dynamically
allocated owner name, an automatically assigned wallet ID, and a randomly generated private
key (a short random string of alphanumeric characters). A wallet maintains a current BTC balance
and a transaction history stored in a dynamically allocated floating-point array. Each deposit,
withdrawal, or transfer should expand this history by one entry.
The system includes a global Exchange entity that maintains static information such as the BTCto-USD conversion rate, the total BTC in circulation, and the number of active wallets. The
exchange rate should only be adjustable via a friend function, simulating restricted
administrative privileges. Whenever a wallet’s balance changes, the total BTC in circulation must
automatically update to maintain consistency.
Wallets should support intuitive operator-based functionality:
• += to deposit BTC into a wallet.
• -= to withdraw BTC (with balance validation).
• ++ and -- to simulate market volatility (increasing or decreasing balance slightly).
• > and < to compare wallet balances.• >> to transfer BTC from one wallet to another.
• [] to access a transaction amount by index in the history.
When a wallet is copied, the copy constructor must assign a new wallet ID and private key while
retaining the BTC balance but resetting the transaction history. Similarly, the assignment
operator must ensure deep copies to prevent shared transaction arrays. Destructors should
securely erase private keys, deallocate all dynamic memory, and announce the wallet’s secure
destruction.
Recursive Mining Mechanism
Each wallet also supports a mining feature that allows earning new BTC through computational
work. This mining operation must be implemented using recursion, arrays, and pointers as
described below — no alternative logic is allowed.
A function named mineCoins() should exist inside the wallet class. It will simulate mining using
an integer array that represents computational “blocks.” The mining function accepts:
1. A pointer to an integer array (representing block data).
2. The total number of blocks in the array.
3. A “target” number to find (e.g., 7).
Mining begins from index 0 and uses recursion to check each block sequentially until it finds the
target value.
• If the target is found, the function should print the index of the successful block and return
that index.
• If not found, the recursion should proceed to the next index.
• If the end of the array is reached with no success, the function should return -1, indicating
failure.
• Each recursive call should print a message such as “Checking block #i...” to visualize
recursion depth.
For every successful mining attempt, the wallet earns a small random BTC reward (between 0.01
and 0.05 BTC). This reward is automatically added to the wallet using the overloaded += operator,
and the total BTC in circulation must be updated via the Exchange.
The mining array must be dynamically allocated using pointers (e.g., int* blocks = new int[size];),
filled with random integers between 0 and 9, and passed to the recursive mining function. After
mining completes, the array should be properly deallocated to prevent memory leaks.
Every wallet object’s destructor should execute automatically at program termination, ensuring
all private keys and transaction histories are securely deleted.A proper menu for each functionality is required