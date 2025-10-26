# Airgead Banking — Compound Interest Visualizer (C++ Console)

A simple console application that helps students see how an investment grows over time **with and without** additional monthly deposits. The app validates user input, computes monthly compounding, and prints two yearly summary tables.

> **Note:** In this implementation, the monthly **deposit is added first**, then monthly interest is applied to the new balance (12 periods per year).

---

## How to Build & Run

```bash
# build (GNU/Clang)
g++ -std=c++17 -O2 AirgeadBanking.cpp -o AirgeadBanking

# run
./AirgeadBanking
```

You’ll be prompted for:

* Initial Investment Amount (>$0)
* Monthly Deposit (≥$0)
* Annual Interest Rate in percent (≥0)
* Number of Years (≥1)

Then press **Enter** to display the reports.

---

## Sample Interaction

```
**********************************
********** Airgead Bank **********
**********************************

Initial Investment Amount: $1000
Monthly Deposit: $50
Annual Interest (%): 5
Number of years: 3

Press Enter to continue...

Balance and Interest Without Additional Monthly Deposits
============================================================
Year                 Year End Balance      Year End Earned Interest
------------------------------------------------------------
1                              1051.16                        51.16
2                              1104.94                        53.78
3                              1161.47                        56.53

Balance and Interest With Additional Monthly Deposits
============================================================
Year                 Year End Balance      Year End Earned Interest
------------------------------------------------------------
1                              1672.97                        72.97
2                              2388.43                        115.46
3                              3137.48                        149.05

Thank you for using Airgead Banking.
```

---

## Flowchart


<img width="3014" height="3840" alt="Airegead Flowchart" src="https://github.com/user-attachments/assets/454fc6df-45cd-41d2-9e7e-cfb7f07e893b" />



---

## What the Project Does (Summary)

* Reads and **validates** four inputs from the user.
* Computes balances with **monthly compounding** for a chosen number of years.
* Produces **two reports**:

  1. growth **without** additional monthly deposits, and
  2. growth **with** the monthly deposit.
* Displays **year-end balance** and **total interest earned** each year in a clear table.

---

## What I Did Particularly Well

* **Input validation & UX:** robust re-prompting with clear error messages; “Press Enter to continue” pause matches the spec.
* **Separation of concerns:** small, focused functions (`readDouble`, `readInt`, `computeSchedule`, `printReport`) and a tiny `main`.
* **Readable output:** aligned, fixed-precision table formatting that’s easy to compare year-over-year.

---

## Where I Could Enhance the Code (and Why It Helps)

* **Configuration & export:** allow exporting the tables to CSV and/or JSON → easier grading, reuse, and sharing.
* **Precision & currency handling:** use a decimal type (or scaled integers in cents) to avoid floating-point rounding artifacts → more accurate financial calcs.
* **Unit tests:** add tests for edge cases (0% interest, large years, zero monthly deposit, deposit-after-interest variant) → safer refactors.
* **Parameterize compounding/order:** toggle “deposit before/after interest” and compounding frequency (monthly/quarterly) → more realistic scenarios.
* **Input trimming & locales:** accept inputs with commas or currency symbols, respect locale for decimal separators → better usability.

---

## Most Challenging Parts & How I Solved Them

* **Monthly compounding logic:** deciding whether to add the deposit before or after interest.
  *Solution:* Implemented “deposit then interest” (documented above) and wrapped it in `computeSchedule`, making it easy to switch later.
* **Clean tables in the console:** getting alignment right with `setw`, `fixed`, and `setprecision`.
  *Solution:* Wrote a single `printReport` function to centralize formatting.

---

## Transferable Skills

* **Input validation patterns** (loops with `cin.fail()` recovery).
* **Decomposition into pure functions** and use of simple data structures (`struct YearRow`, `vector<YearRow>`).
* **Formatting and reporting** for console apps—useful for CLI tools, quick diagnostics, and teaching demos.

---

## Maintainability, Readability, and Adaptability

* **Consistent naming** and **inline comments** for clarity.
* **Modular functions** keep responsibilities clear and make unit testing straightforward.
* **Single source of truth** for calculations (`computeSchedule`) so changes (e.g., compounding rules) are localized.
* **No global state**; parameters are explicit → easier to extend or plug into a GUI or web service later.

---

## File List

* `AirgeadBanking.cpp` — complete program (input, validation, computation, reporting)
* `README.md` — this document (overview, flowchart, notes)
