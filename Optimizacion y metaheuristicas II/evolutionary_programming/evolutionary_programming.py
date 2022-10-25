import numpy as np

class EvolutionaryProgramming:

    def __init__(self, func, bounds, args, popsize, iterations, sigma):
        self.func = func
        self.args = np.array(args)
        self.bounds = np.array(bounds)
        self.popsize = popsize
        self.population = None
        self.fitness = None
        self.best_fitness = -1
        self.best_solution = np.zeros(len(bounds))
        self.iterations = iterations
        self.sigma = sigma
    
    def init_population(self):
        nvar = len(self.bounds)
        self.population = np.zeros((self.popsize,nvar*2))
        self.fitness = np.zeros((self.popsize))
        for i in range(nvar):
            vmin, vmax = self.bounds[i,0], self.bounds[i,1]
            vmut = np.abs(vmax-vmin)/10
            self.population[:, i] = np.random.uniform(self.bounds[i][0], self.bounds[i][1], size=self.popsize)
            self.population[:, i+nvar] = np.abs(np.random.normal(loc=0,scale=vmut,size=(self.popsize))) + 0.001
        for i in range(self.popsize):
            self.fitness[i] = self.func(self.population[i, :nvar], *self.args)

    def mutation(self):
        nvar = len(self.bounds)
        new_population = np.zeros((self.popsize,nvar*2))
        new_population_fitness = np.zeros((self.popsize))
        for i in range(nvar):
            vmin, vmax = self.bounds[i,0],self.bounds[i,1]
            vmut = np.abs(vmax-vmin)/10
            new_population[:, i] = self.population[:, i] + np.random.normal(loc=0,scale=vmut,size=(self.popsize))
            new_population[:, i+nvar]  = self.population[:, i+nvar] * (1.0 + np.random.normal(loc=0,scale=self.sigma,size=(self.popsize)) )
        for i in range(self.popsize):
            new_population_fitness[i] = self.func(new_population[i, :nvar], *self.args)
        return new_population, new_population_fitness
    
    def survivor_selection(self, new_population, new_population_fitness):
        new_population = np.concatenate((self.population, new_population), axis=0)
        new_fitness = np.concatenate((self.fitness, new_population_fitness), axis=0)
        idx = np.argsort(new_fitness)
        self.population = new_population[idx[:self.popsize], :]
        self.fitness = new_fitness[idx[:self.popsize]]

    def solve(self):
        self.init_population()
        for _ in range(self.iterations):
            print('Iteration:', _, 'Best fitness:', self.fitness.min())
            print('Best solution:', self.best_solution) 
            new_population, new_population_fitness = self.mutation()
            self.survivor_selection(new_population, new_population_fitness)
            # Select best solution
            idx = np.argmin(self.fitness)
            if self.fitness[idx] < self.best_fitness or self.best_fitness == -1:
                self.best_fitness = self.fitness[idx]
                self.best_solution = self.population[idx, :len(self.bounds)]
        # P: el arreglo con la solución
        # nit: número de generaciones
        # fun: fitness del mejor individuo al terminar la ejecución
        # nfev: número de veces que se manda llamar la función func
        return self.best_solution, self.iterations, self.best_fitness, self.iterations*self.popsize
        
def evolutionary_programming(func, bounds, args=(), popsize=30, iterations=100, sigma=0.1):
    ep = EvolutionaryProgramming(func, bounds, args, popsize, iterations, sigma)
    ep.init_population()
    P, nit, fun, nfev = ep.solve()
    return P, nit, fun, nfev