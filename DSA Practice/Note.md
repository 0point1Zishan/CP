# Array


## Simple Notes for Zero Matrix Algorithm (Optimized Space):

### Optimized In-Place Zero Matrix Algorithm

#### 1. Mark rows & columns using first row/column
- As you scan each cell `(i, j)`, when you see a `0`:
  - Set `matrix[i][0] = 0` to mark **row** _i_.
  - If `j > 0`, set `matrix[0][j] = 0` to mark **column** _j_.
  - If the zero is in **column** 0, don’t overwrite `matrix[0][0]`—instead record that in a separate flag `col0 = 0`.

#### 2. Use markers to zero out the inner submatrix
- For every cell `(i, j)` with `i > 0` and `j > 0`:
  - If **either** `matrix[i][0] == 0` **or** `matrix[0][j] == 0`, then set `matrix[i][j] = 0`.

#### 3. Finally zero the first row and first column
- If `matrix[0][0] == 0`, set every element in **row 0** to `0`.
- If `col0 == 0`, set every element in **column 0** to `0`.

---

#### Why It Works & Why Ordering Matters
1. **O(1) Extra Space**  
   Reuses the input matrix for bookkeeping instead of allocating extra arrays.

2. **Three-Pass Process**  
   1. **Marking Pass** — Record zeros using the first row/column markers and `col0`.  
   2. **Zeroing Pass** — Zero out cells `(1…n–1, 1…m–1)` based on those markers.  
   3. **Cleanup Pass** — Finally update the first row and first column **last**, so you never overwrite markers before they’re used.
<br><br><br><br><br>
<hr>

## Rotate Image by 90 degree
#### Approach:

1. Transpose the matrix. (transposing means changing columns to rows and rows to columns)

2. Reverse each row of the matrix.
<br><br><br><br><br>
<hr>


## Rotate Image by 90 degree
code: link()
