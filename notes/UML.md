# Unified Modeling Language (UML)

UML is an industry-standard graphical language used for specifying, visualizing, constructing, and documenting the artifacts of software systems. It simplifies the complex process of software design and is widely employed in Object-Oriented Analysis and Design (OOAD) for software projects.

## Why Use UML?

- **Graphical Notation:** UML utilizes graphical notations that are clearer than natural language (which can be imprecise) and code (which can be too detailed).

- **Overall View:** Helps in acquiring an overall view of a system, making it easier to understand and communicate various aspects.

- **Language and Technology Independence:** UML is not dependent on any specific programming language or technology, making it versatile and widely applicable.

- **Standardization:** UML promotes standardization in software design, moving from fragmentation to a unified approach.

## Uses for UML

- **Sketching:** Utilized as a sketch to communicate aspects of a system, often done on whiteboards or paper to quickly convey ideas.

- **Forward Design:** Used in the early stages of software development, doing UML before actual coding to plan and design the system.

- **Backward Design:** Employed after coding as documentation to capture the design decisions and structure of the implemented system.

- **Blueprint:** Can serve as a complete design blueprint for a system that needs to be implemented.

- **CASE Tools:** Often used with Computer-Aided Software Engineering (CASE) tools for more formal and detailed modeling.

- **Programming Language:** With the right tools, code can be auto-generated and executed from UML, offering an alternative way to implement software.

**Note:** Using UML as a programming language is practical if it significantly speeds up the development process compared to coding directly in a traditional programming language.

## Types of UML Diagrams

Unified Modeling Language (UML) encompasses various diagram types that serve different purposes throughout the software development life cycle. Here's a subset of UML diagrams that are widely used:

## 1. Use Case Diagram

- **Purpose:** Describes the interactions between users (actors) and a system to showcase the system's functionality from a user's perspective.
- **Elements:** Actors, Use Cases, Relationships.

## 2. Class Diagram

- **Purpose:** Represents the static structure of a system, showcasing classes, their attributes, methods, and relationships.
- **Elements:** Classes, Attributes, Methods, Relationships.

## 3. Sequence Diagram

- **Purpose:** Illustrates the interactions between objects over time, emphasizing the sequence of messages exchanged between them.
- **Elements:** Lifelines, Messages, Activation Bars.

## 4. Collaboration or Communication Diagram

- **Purpose:** Similar to Sequence Diagram, emphasizes the relationships between objects but from a different perspective.
- **Elements:** Objects, Links, Messages.

## 5. State Diagram

- **Purpose:** Describes the various states an object can be in and transitions between those states based on events.
- **Elements:** States, Transitions, Events.

## 6. Activity Diagram

- **Purpose:** Represents the flow of activities within a system, showcasing the dynamic aspects of a process.
- **Elements:** Actions, Decision Nodes, Flow Control Elements.

**Note:** These diagrams are a subset of the various UML diagrams available, each serving a specific purpose in visualizing different aspects of a software system during its development life cycle.

## Use-Case Diagrams

A Use-Case Diagram is a type of diagram in Unified Modeling Language (UML) that represents a set of use cases, providing a high-level view of the interactions between external users (actors) and the software system.

## Components of a Use-Case Diagram

### Actors

- **Definition:** A role played by a user or an external system concerning the system under consideration.
- **Example:** Human users, inanimate physical objects (e.g., a robot), external systems requiring information.

### Use Case

- **Definition:** A set of scenarios describing an interaction between a user (actor) and the system, capturing user requirements.
- **Example:** A specific functionality or feature that the system provides to its users.

### System Boundary

- **Representation:** A rectangle that delineates the boundary between actors and the system.
- **Purpose:** Clearly defines what is inside the system and what is external to it.

## Purpose of Use-Case Diagrams

- **Modeling Interaction:** Illustrates the interactions between external users and the system.
- **User Scenarios:** Captures user requirements through various scenarios.
- **Contract:** Serves as a contract between end users and software developers, providing a shared understanding of system functionality.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/c1a3a392-22be-4f6e-872c-f96a0fa6209a)

## Use-Case Diagram Relationships

## Association

- **Representation:** Solid line connecting an actor and a use case.
- **Purpose:** Illustrates communication between an actor and a use case.
- **Example:** A customer (actor) associating with the "Place Order" use case.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/bf0a91f5-48d3-4b10-af4f-61507a5e87c9)

## Generalization

- **Representation:** Line with a triangular arrowhead pointing toward the parent use case.
- **Purpose:** Represents a relationship between a general use case and a specialized use case.
- **Example:** A general use case "Manage Account" being specialized by "Create Account" and "Update Account."

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/15a2d0ee-17c4-4af3-ba1e-9c15332b80d4)

## Include

- **Representation:** Dotted line labeled <<include>>, starting at the base use case and ending with an arrow pointing to the include use case.
- **Purpose:** Indicates that a chunk of behavior is similar across multiple use cases.
- **Usage:** Instead of duplicating the description of behavior, use "include."
- **Example:** "Login" use case including "Authentication" behavior.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/dbca7fc8-f3ee-4afe-93f1-35c28ebdd239)

## Extend

- **Representation:** Dotted line labeled <<extend>> with an arrow toward the base case.
- **Purpose:** Signifies that the extending use case may add behavior to the base use case.
- **Usage:** The base class declares "extension points" for possible extensions.
- **Example:** "Make Payment" use case extending "Place Order" for additional payment methods.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/7660c603-c80c-46ee-af51-ddb29b6bc823)

## Example:

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/edc0b934-d967-4a1a-bb89-454f1e030e45)

- Both Make Appointment and Request Medication include Check Patient Record as a subtask (include)
- The extension point is written inside the base case Pay bill; the extending class Defer payment adds the behavior of this extension point. (extend)
- Pay Bill is a parent use case and Bill Insurance is the child use case. (generalization)


## Class diagram
-  A class diagram depicts classes and their interrelationships
- Used for describing structure and behavior in the use cases
- Provide a conceptual model of the system in terms of entities and their relationships
- Used for requirement capture, end-user interaction
- Detailed class diagrams are used for developers
- Each class is represented by a rectangle subdivided into three compartments
  - Name
  - Attributes
  - Operations
- Modifiers are used to indicate the visibility of attributes and operations.
  - ‘+’ is used to denote Public visibility (everyone)
  - ‘#’ is used to denote Protected visibility (friends and derived)
  - ‘-’ is used to denote Private visibility (no one)
- By default, attributes are hidden and operations are visible.

## Class attributes
- attributes (fields, instance variables)
  - visibility name: type [count] = default_value
  - visibility: <br />'+' public
                <br />'#' protected
                <br />'-' private
                <br />'~' package (default)
                <br />'/' derived
- underline <ins> static attributes </ins>
- **derived attribute**: not stored, but can be computed from other attribute values
- attribute example:<br />
`- balance : double = 0.00`
<br />

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/0932e3f8-208c-44c1-bc17-ced0bfcd20fb)

## Diagram of one class
- class name in top of box
  - write <<interface>> on top of interfaces' names
  - use italics for an abstract class name
- attributes (optional)
  - should include all fields of the object
- operations / methods (optional)
  - may omit trivial (get/set) methods
  -should not include inherited methods

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/23716f04-8a29-46b1-858d-0e112de8553f)

## comments:
- represented as a folded note, attached to the appropriate class/method/etc by a dashed line

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/e2a49b07-9e74-41d5-b61b-5b5255c58385)

## OO Relationships
- There are two kinds of Relationships
  - Generalization (parent-child relationship)
  - Association (student enrolls in course)

- generalization: an inheritance relationship
  - inheritance between classes
  - interface implementation
- association: a usage relationship
  - dependency
  - aggregation
  - composition
  
## Generalization relationships

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/7369e957-3808-4551-bc22-9f1e4e6856e1)

- Inheritance is a required feature of object orientation.<br/>
- Generalization expresses a parent/child relationship among related classes.<br/>
- Used for abstracting details in several layers.

- generalization (inheritance) relationships
  - hierarchies drawn top-down with arrows pointing upward to parent
  - line/arrow styles differ, based on whether parent is a(n):
    - class: solid line, black arrow
    - abstract class: solid line, white arrow
    - interface: dashed line, white arrow
- we often don't draw trivial / obvious generalization relationships, such as drawing the Object class as a parent
  
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/fbbe3d7f-fd09-4f7b-9eec-4e24f1d80721)

## Associational relationships
- Represent the relationship between instances of classes
  - Student enrolls in a course
  - Courses have students
  - Courses have exams
- Association has two ends
  - Role names (e.g. enrolls)
  - Multiplicity (e.g. One course can have many students)
  - Navigability (unidirectional, bidirectional)
- associational (usage) relationships
  1. multiplicity (how many are used)
    - `*` = 0, 1, or more
    - `1` = 1 exactly
    - `2..4` = between 2 and 4, inclusive
    - `3..*` = 3 or more
  2. name (what relationship the objects have)
  3. navigability (direction)

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/b774ee52-852a-4199-a141-3dea8c77aac3)

## Association: Multiplicity and Roles

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/1d5850c8-14d2-49a3-9845-e8f381c8ca8b)

## Multiplicity of associations
- one-to-one
  - each student must carry exactly one ID card

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/d50f40f5-56df-4bce-a912-e0c14106e514)

- one-to-many
  - one rectangle list can contain many rectangles

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/25a4219b-490b-4860-b3c0-df2bdf223e50)

## Dependency Relationships
A dependency indicates a semantic relationship between two or
more elements. The dependency from CourseSchedule to Course exists
because Course is used in both the add and remove operations of
CourseSchedule.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/c0a8103f-b08f-44e2-a7dd-584e0991ab48)

## Association types
- aggregation: "is part of"
  - symbolized by a clear white diamond

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/3cbadf76-e9d1-4d9b-88dc-d24859c2273b)

- composition: "is entirely made of"
  - stronger version of aggregation
  - the parts live and die with the whole
  - symbolized by a black diamond

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/67cc2a7d-594c-4a77-9f03-2a102ee6c9db)

## Association: Model to Implementation

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/29e73109-3911-4bb9-93c9-fc18abf55ced)

```cpp
Class Student {
Course enrolls[4];
}
Class Course {
Student have[];
}
```
## Aggregation vs. Composition
- Aggregations
  may form "part of" the association, but may not be essential to it. They may also exist independent of the aggregate. e.g. Apples may exist independently of the bag.
- Composition is a strong form of association
  - components have only one owner
  - components cannot exist independently of their owner
  - components live or die with their owner. E.g. Each car has an engine that can not be shared with other cars.
## Examples:

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/361bf199-fb6b-46bd-938e-475a7304eb6d)

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/4ab9a739-6038-47aa-8ef0-c65d0e2123c1)

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/f9164aaf-308d-4b97-bdf4-39c28f2688b4)

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/aa581845-a9dc-465d-aab9-c280d3b21f52)

## Interaction Diagrams
- show how objects interact with one another
- UML supports two types of interaction diagrams
  - Sequence diagrams: A sequence diagram is an interaction diagram that emphasizes the time ordering of messages. It shows a set of objects and the messages sent and received by those objects.
  - Collaboration or Communication diagrams
 
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/592ac276-1478-4dfb-99cf-bbc9f517decb)

## Sequence Diagram: Object interaction
- Self-Call: A message that an Object sends to itself.
- Condition: indicates when a message is sent. The message is sent only if the condition is true

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/4189dea0-171b-4f59-9dda-e16b9994fdb0)

## Sequence Diagrams – Object Life Spans
- Creation
  - Create message
  - Object life starts at that point
- Activation
  - Symbolized by rectangular stripes
  - Place on the lifeline where the object is activated.
  - Rectangle also denotes when the object is deactivated.
- Deletion
  - Placing an ‘X’ on lifeline
  - Object’s life ends at that point

 ![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/e7e28b3e-1f82-48f7-971a-fbc5d3c57555)

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/4f1ba73d-cb6f-4eb1-ac5b-998bd3e993ac)

## Sequence Diagram
- Sequence diagrams demonstrate
the behavior of objects in a use case
by describing the objects and the
messages they pass.
- The horizontal dimension shows the
objects participating in the interaction.
- The vertical arrangement of
messages indicate their order.
- The labels may contain the
sequence number to indicate
concurrency

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/9418c6c5-9d88-4c6e-a1ad-e4ab858952d2)

## Interaction Diagrams: Collaboration or Communication Diagrams

- Collaboration diagrams are equivalent to sequence diagrams. All the features of sequence diagrams are equally applicable to collaboration diagrams
- A collaboration diagram emphasizes the relationship of the objects that
participate in an interaction. Unlike a sequence diagram, you don’t have to show the lifeline of an object explicitly in a collaboration diagram. The sequence of events are indicated by sequence numbers preceding messages
- Both a collaboration diagram and a sequence diagram derive from the same
information in the UML’s metamodel, so you can take a diagram in one form and convert it into the other. They are semantically equivalent.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/85989d0a-494d-43a3-824a-febfa394b148)
<br/>
**Note:**<br />
- Use a sequence diagram when the transfer of information is the focus of attention
- Use a collaboration diagram when concentrating on the classes

## Collaboration Diagram

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/ca76a0f6-5836-4e21-a92c-8e676858b3e6)

## State Diagrams (Billing Example)
State Diagrams show the sequences of states an object goes through during its life cycle in response to stimuli, together with its responses and actions; an abstraction of all possible behaviors.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/efbf225d-bab5-438e-9b2d-c121d647ae07)

## State Diagrams (Traffic light example)

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/95008b69-9e17-479b-ac1d-0f336d5aec7c)

## Activity Diagrams
- An activity diagram is essentially a flowchart, showing the flow of control from activity to activity.
- Activity diagrams are a variation of state diagrams that focuses on the flow of actions and event

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/8294a59b-b4b9-4b61-90cd-7821c51f0113)
