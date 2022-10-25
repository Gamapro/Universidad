import numpy as np

class differential_evolution:
    def __init__(self, obj_func, bounds, args = None, population_size = 100, max_iters = 150, Cr= 0.7):
        self.obj_func = obj_func
        self.bounds = bounds
        self.args = args
        self.popsize = population_size
        self.maxiter = max_iters
        self.Cr = Cr

    def init_population(self):
        return np.array([np.random.uniform(self.bounds[i][0], self.bounds[i][1], self.popsize) for i in range(len(self.bounds))]).T

    def calculate_fitness(self, population):
        return np.apply_along_axis(self.obj_func, 1, population, *self.args)

    def solve(self, verbose = False):
        generation = self.init_population()
        fitness = self.calculate_fitness(generation)

        for i in range(self.maxiter):
            x1, x2, x3 = np.random.randint(0, self.popsize, (3, self.popsize))

            F = np.random.uniform(0, 1, (self.popsize,1))
            vs = generation[x1] + F * (generation[x2] - generation[x3])

            vs = np.array([np.clip(vs[:, j], self.bounds[j][0], self.bounds[j][1]) for j in range(len(self.bounds))]).T

            probs = np.random.uniform(0, 1, (self.popsize, len(self.bounds)))
            mask = probs < self.Cr
            vs = np.where(mask, vs, generation)
            vs_fitness = self.calculate_fitness(vs)

            fitness_mask = vs_fitness < fitness
            fitness = np.where(fitness_mask, vs_fitness, fitness)
            generation = np.where(fitness_mask[:, None], vs, generation)

            if verbose:
                print("Iteration: ", i, "Best fitness: ", np.min(fitness))

        return generation[np.argmin(fitness)], np.min(fitness)