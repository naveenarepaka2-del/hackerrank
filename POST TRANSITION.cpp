#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct package {
    char id[16];
    int weight;
};

struct post_office {
    int min_weight;
    int max_weight;
    int packages_count;
    struct package *packages;
};

struct town {
    char name[32];
    int offices_count;
    struct post_office *offices;
};

typedef struct package package;
typedef struct post_office post_office;
typedef struct town town;

void print_all_packages_in_town(town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_packages(post_office *source, post_office *target) {
    int new_source_count = 0;
    package *new_source = malloc(source->packages_count * sizeof(package));

    for (int i = 0; i < source->packages_count; i++) {
        package p = source->packages[i];
        if (p.weight >= target->min_weight && p.weight <= target->max_weight) {
            target->packages = realloc(target->packages, (target->packages_count + 1) * sizeof(package));
            target->packages[target->packages_count++] = p;
        } else {
            new_source[new_source_count++] = p;
        }
    }

    free(source->packages);
    source->packages = new_source;
    source->packages_count = new_source_count;
}

town town_with_most_packages(town* towns, int towns_count) {
    int max_packages = -1;
    town result = towns[0];
    for (int i = 0; i < towns_count; i++) {
        int total = 0;
        for (int j = 0; j < towns[i].offices_count; j++) {
            total += towns[i].offices[j].packages_count;
        }
        if (total > max_packages) {
            max_packages = total;
            result = towns[i];
        }
    }
    return result;
}

town find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            return towns[i];
        }
    }
    return towns[0]; // guaranteed to exist
}

int main() {
    int towns_count;
    scanf("%d", &towns_count);

    town *towns = malloc(towns_count * sizeof(town));

    for (int i = 0; i < towns_count; i++) {
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(towns[i].offices_count * sizeof(post_office));

        for (int j = 0; j < towns[i].offices_count; j++) {
            int packages_count, min_w, max_w;
            scanf("%d %d %d", &packages_count, &min_w, &max_w);
            towns[i].offices[j].min_weight = min_w;
            towns[i].offices[j].max_weight = max_w;
            towns[i].offices[j].packages_count = packages_count;
            towns[i].offices[j].packages = malloc(packages_count * sizeof(package));

            for (int k = 0; k < packages_count; k++) {
                scanf("%s %d", towns[i].offices[j].packages[k].id, &towns[i].offices[j].packages[k].weight);
            }
        }
    }

    int queries;
    scanf("%d", &queries);

    for (int q = 0; q < queries; q++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char town_name[32];
            scanf("%s", town_name);
            town t = find_town(towns, towns_count, town_name);
            print_all_packages_in_town(t);
        } else if (type == 2) {
            char town1[32], town2[32];
            int index1, index2;
            scanf("%s %d %s %d", town1, &index1, town2, &index2);
            town t1 = find_town(towns, towns_count, town1);
            town t2 = find_town(towns, towns_count, town2);
            send_all_packages(&t1.offices[index1], &t2.offices[index2]);
        } else if (type == 3) {
            town t = town_with_most_packages(towns, towns_count);
            printf("Town with the most number of packages is %s\n", t.name);
        }
    }

    return 0;
}

