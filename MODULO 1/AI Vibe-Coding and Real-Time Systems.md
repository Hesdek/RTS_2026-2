# Vibe Coding in Real-Time Systems: Risks and Considerations

**Vibe coding** is a development paradigm where you describe your software's goals in natural language to an AI, which then handles the technical implementation. 

For **real-time systems**—which must process data within strict timing constraints, such as streaming and gaming—this approach can be **highly risky** unless guided by strict human oversight, as AI-generated code may overlook critical hardware constraints, execution-time requirements, and latency limitations.

## What is Vibe Coding?

Coined by AI researcher **Andrej Karpathy**, *vibe coding* shifts development from manual, line-by-line coding toward **intent-driven design**. Instead of focusing primarily on syntax or low-level implementation details, the developer describes the desired behavior or outcome and allows large language models (LLMs) to generate much of the implementation.

The approach can significantly accelerate prototyping and experimentation. However, it also changes the role of the developer: 

> **understanding, validating, and verifying the generated implementation becomes increasingly important**.

## Vibe Coding in Real-Time Systems: The Risks

Real-time systems must respond to inputs within specified time limits, known as **deadlines**. In a real-time system, producing the correct result is not sufficient if the result is produced too late. Consequently, **temporal correctness** is an essential part of system correctness.

Applying vibe coding to these environments without appropriate architectural and verification practices can create several important risks.

### 1. Lack of Determinism

Real-time systems require a high degree of **predictability**. Their behavior must be sufficiently bounded to allow developers to reason about worst-case execution times, response times, scheduling, and resource utilization.

LLMs can generate different implementations depending on prompts, context, or subsequent interactions. More importantly, generated implementations may contain algorithms, abstractions, libraries, or runtime mechanisms whose execution behavior is difficult to bound.

This creates a potential mismatch:

> **AI-generated software may be functionally correct without necessarily being temporally predictable.**

For real-time software, the relevant question is therefore not only:

> *"Does the program produce the correct result?"*

but also:

> *"Can we establish that it produces the result within the required deadline?"*

### 2. Hidden Latency

AI-generated code may introduce inefficient loops, unnecessary abstractions, excessive memory operations, blocking operations, background processes, or other mechanisms that increase execution time.

In applications with strict timing requirements, apparently small sources of latency can accumulate and produce:

- system stuttering;
- packet drops;
- missed deadlines;
- delayed responses;
- increased jitter;
- degraded quality of service.

This is particularly relevant when the generated code depends on libraries or runtime components whose internal behavior is not obvious from the high-level code.

### 3. Memory and Hardware Constraints

Real-time software —particularly embedded software— frequently executes on hardware with constrained resources.

These constraints can include:

- limited RAM;
- limited flash/storage;
- restricted CPU performance;
- limited communication bandwidth;
- energy constraints;
- hardware-specific peripherals;
- interrupt limitations;
- cache and memory-access effects.

An AI-generated implementation may introduce unnecessary data structures, dynamic memory allocation, large dependencies, or resource-intensive algorithms.

Consequently, code that works correctly on a development computer may fail when deployed on the target hardware.

## The Fundamental Problem

The central issue can therefore be summarized as:

$$
\boxed{
\text{Functional Correctness}
\neq
\text{Real-Time Correctness}
}
$$

A vibe-coded implementation may successfully demonstrate that:

> "The program works."

However, an **RTS engineer** must additionally demonstrate that:

> "The program works **within the required temporal, resource, and hardware constraints**, including relevant worst-case conditions."

This distinction is particularly important when applying AI-assisted development to **hard real-time systems**, where a missed deadline can constitute a system failure.

## References

### Vibe Coding

**[1]** Kairntech. *Vibe Coding: What It Is, How It Works, and Why It's Transforming Software Development.*  
https://kairntech.com/blog/articles/vibe-coding-what-it-is-how-it-works-and-why-its-transforming-software-development/

**[2]** YouTube. *Vibe Coding* — short video.  
https://www.youtube.com/shorts/6bqqI4d0VHU

**[3]** Nearform. *Vibe Coding Is Fun Until You Have to Ship at Scale.*  
https://nearform.com/digital-community/vibe-coding-is-fun-until-you-have-to-ship-at-scale/

**[4]** Retool. *What Is Vibe Coding?*  
https://retool.com/blog/what-is-vibe-coding

**[5]** Streamkap. *Data Stream Processing.*  
https://streamkap.com/resources-and-guides/data-stream-processing

### What is Vibe Coding?

**[1]** Andrej Karpathy. *Vibe Coding* — YouTube presentation.  
https://www.youtube.com/watch?v=TgMtUBZ0lpM&t=66

**[2]** Wikipedia. *Vibe Coding.*  
https://en.wikipedia.org/wiki/Vibe_coding

**[3]** Medium. *Introducción al concepto de vibe coding.*  
https://medium.com/@j92riquelme/introducci%C3%B3n-al-concepto-de-vibe-coding-b0944618917d

### Real-Time Systems

**[1]** YouTube. *Real-Time Systems* — short video.  
https://www.youtube.com/shorts/6bqqI4d0VHU

**[2]** All About Circuits. *Introduction to Real-Time Embedded Systems.*  
https://www.allaboutcircuits.com/technical-articles/introduction-to-real-time-embedded-systems/

**[3]** SAM Solutions. *Real-Time Embedded Systems.*  
https://sam-solutions.com/blog/real-time-embedded-systems/

**[4]** Naukri Code360. *Tasks in Real-Time Systems.*  
https://www.naukri.com/code360/library/tasks-in-real-time-systems

**[5]** Ably. *4 Lessons from Scaling a Startup.*  
https://ably.com/blog/4-lessons-from-scaling-a-startup

### Risks of Vibe Coding

**[1]** Focused Chaos. *Vibe Coding Without System Design Is a Trap.*  
https://www.focusedchaos.co/p/vibe-coding-without-system-design-is-a-trap

**[2]** Flatlogic. *What's the Problem with Vibe Coding? Honest Review.*  
https://flatlogic.com/blog/what-s-the-problem-with-vibe-coding-honest-review/

**[3]** YouTube. *Vibe Coding and Software Development.*  
https://www.youtube.com/watch?v=Pqj_EQIyhUU

**[4]** YouTube. *Vibe Coding* — short video.  
https://www.youtube.com/shorts/6bqqI4d0VHU

### Determinism

**[1]** Reddit r/embedded. *How is realtime software designed?*  
https://www.reddit.com/r/embedded/comments/1m1btwv/how_is_realtime_software_designed/

**[2]** *Embedded Systems — Theory and Design Methodology.*  
https://www.embeddedrelated.com/Documents/Embedded_Systems_-_Theory_and_Design_Methodology.pdf

**[3]** Kairntech. *Vibe Coding: What It Is, How It Works, and Why It's Transforming Software Development.*  
https://kairntech.com/blog/articles/vibe-coding-what-it-is-how-it-works-and-why-its-transforming-software-development/

### Hidden Latency

**[1]** ASOS Tech Blog. *Introducing Test-Driven Vibe Development.*  
https://medium.com/asos-techblog/introducing-test-driven-vibe-development-0effe6430691

**[2]** The New Stack. *Vibe Coding: When AI Writes the Code, Who Secures It?*  
https://thenewstack.io/vibe-coding-when-ai-writes-the-code-who-secures-it/

**[3]** LinkedIn. *Discussion on Vibe Coding Complex Software.*  
https://www.linkedin.com/posts/svpino_i-dont-believe-you-can-vibe-code-complex-activity-7399796727702142976-eB4I

**[4]** Mbedded.ninja. *Logging on an Embedded System.*  
https://blog.mbedded.ninja/programming/logging-on-an-embedded-system/

**[5]** Robotics Knowledgebase. *Choose a Simulation / Robotics Project Guide.*  
https://roboticsknowledgebase.com/wiki/robotics-project-guide/choose-a-sim/

### Memory and Hardware Constraints

**[1]** Arizona State University. *Software and Simulation Modeling for Real-Time Software-Intensive Systems.*  
http://acims.asu.edu/wp-content/uploads/sites/18/2012/02/Software-and-Simulation-Modeling-for-Real-time-Software-intensive-System.pdf

**[2]** ScienceDirect. *Embedded Software.*  
https://www.sciencedirect.com/topics/computer-science/embedded-software

**[3]** Showrunner. *Real-Time Engine — Virtual Production Glossary.*  
https://showrunner.tech/virtual-production-glossary/real-time-engine

**[4]** Codewave. *Embedded Software Development Guide.*  
https://codewave.com/insights/embedded-sw-development-guide/

**[5]** Medium. *From Heads-Down to Hands-Off: A Journey into Responsible Vibe Coding.*  
https://medium.com/@harsz89/from-heads-down-to-hands-off-a-journey-into-responsible-vibe-coding-3d81a1c5634c