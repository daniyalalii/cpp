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
