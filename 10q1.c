LAB 10 Q1
#include <stdio.h>
#include <string.h>
int main() {
int i, j, k;
int n = 5;
int m = 3;
int alloc[n][m];
int max[n][m];
int total[3] = {10, 5, 7};
for (int i = 0; i<n; i++) {
for (int j = 0; j<m; j++) {
printf("Resource allocated to P%d by %c: ", i, 65+j);
scanf("%d", &alloc[i][j]);
printf("Resource maximum needed by P%d from %c: ", i, 65+j);
scanf("%d", &max[i][j]);
}
}
int avail[3];
for (int i = 0; i<m; i++) {
int tot = 0;
for (int j = 0; j<n; j++) {
tot = tot + alloc[j][i];
}
avail[i] = total[i] - tot;
}
int f[n], ans[n], ind = 0;
for (k = 0; k < n; k++) {
f[k] = 0;
}
printf("\nNeed Matrix:\n");
int need[n][m];
for (i = 0; i < n; i++) {
for (j = 0; j < m; j++) {
need[i][j] = max[i][j] - alloc[i][j];
printf("%d\t", need[i][j]);
}
printf("\n");
}
int y = 0;
for (k = 0; k < 5; k++) {
for (i = 0; i < n; i++) {
if (f[i] == 0) {
int flag = 0;
for (j = 0; j < m; j++) {
if (need[i][j] > avail[j]){
flag = 1;
break;
}
}
if (flag == 0) {
ans[ind++] = i;
for (y = 0; y < m; y++)
avail[y] += alloc[i][y];
f[i] = 1;
}
}
}
}
int flag = 1;
for(int i=0;i<n;i++) {
if(f[i]==0) {
flag=0;
printf("The following system is not safe");
break;
}
}
if(flag==1) {
printf("Following is the SAFE Sequence\n");
for (i = 0; i < n - 1; i++)
printf(" P%d ->", ans[i]);
printf(" P%d", ans[n - 1]);
}
printf("\n\nP1 (1, 0, 2) arrives:\n");
int new[3] = {1, 0, 2};
flag = 0;
for (int i = 0; i<m; i++) {
if (max[1][i] > new[i]) {
if (new[i] < avail[i]) {
flag = 1;
}
}
}
if (flag == 1) {
int alloc1[n][m];
memcpy(alloc1, alloc, sizeof(alloc));
int need1[n][m];
memcpy(need1, need, sizeof(need));
int avail1[3];
for (int i = 0; i<m; i++) {
int tot = 0;
for (int j = 0; j<n; j++) {
tot = tot + alloc[j][i];
}
avail1[i] = total[i] - tot;
}
for (int i = 0; i<m; i++) {
alloc1[1][i] += new[i];
need1[1][i] -= new[i];
avail1[i] -= new[i];
}
printf("Granted\n");
printf("\nUpdated allocated table:\n");
for (int i=0; i<n; i++) {
for (int j=0; j<m; j++) {
printf("%d\t", alloc1[i][j]);
}
printf("\n");
}
printf("\nUpdated need table:\n");
for (int i=0; i<n; i++) {
for (int j=0; j<m; j++) {
printf("%d\t", need1[i][j]);
}
printf("\n");
}
printf("\nUpdated available table:\n");
for (int i=0; i<m; i++) {
printf("%d\t", avail1[i]);
}
} else {
printf("\nCannot accomodate\n");
}
printf("\n\nP4 (3, 3, 0) arrives:\n");
int new1[3] = {3, 3, 0};
flag = 0;
for (int i = 0; i<m; i++) {
if (max[4][i] > new1[i]) {
if (new1[i] < avail[i]) {
flag = 1;
}
}
}
if (flag == 1) {
printf("\nGranted\n");
} else {
printf("\nCannot accomodate\n");
}
printf("\n\nP0 (0, 2, 0) arrives:\n");
int new2[3] = {0, 2, 0};
flag = 0;
for (int i = 0; i<m; i++) {
if (max[0][i] > new2[i]) {
if (new2[i] < avail[i]) {
flag = 1;
}
}
}
if (flag == 1) {
printf("\nGranted\n");
} else {
printf("\nCannot accomodate\n");
}
}
